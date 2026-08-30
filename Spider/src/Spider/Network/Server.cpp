#include "spch.h"
#include "Server.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <poll.h>
#include <unistd.h>

namespace Spider {

namespace Util {

uint64_t GenerateFNVHash(const std::string_view &str) {
  uint64_t hash = 0xcbf29ce484222325; // FNV offset basis
  uint64_t fnv_prime = 0x00000100000001B3; // FNV prime

  for (char c : str) {
    hash ^= static_cast<uint64_t>(c);
    hash *= fnv_prime;
  }
  return hash;
}

}

Server::Server(const uint16_t &port) {
  // Create the socket
  m_FD = socket(AF_INET, SOCK_STREAM, 0);
  if (m_FD < 0) { // Server Failed to Create!
    std::cerr << "Server socket creation failed\n";
    return;
  }

  // Socket Options
  int opt = 1;
  setsockopt(m_FD, SOL_SOCKET, SO_REUSEADDR, (const char *)&opt, sizeof(opt));

  int flags = fcntl(m_FD, F_GETFL, 0);
  fcntl(m_FD, F_SETFL, flags | O_NONBLOCK); // Sets the socket to non blocking

  // Create and bind address
  sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(m_FD, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    std::cerr << "Server failed to bind\n";
    close(m_FD);
    return;
  }

  listen(m_FD, 3); // 3 Maximum pending connections

  m_IsValid = true; // Do very last
}

Server::~Server() {
  if (m_IsValid) {
    close(m_FD);
  }
}

void Server::Update() {
  pollfd pfd;
  pfd.fd = m_FD;
  pfd.events = POLLIN;
  pfd.revents = 0;

  int ret = poll(&pfd, 1, 0);

  if (ret > 0 && (pfd.revents & POLLIN)) {
    int client_fd = accept(m_FD, nullptr, nullptr);
    if (client_fd >= 0) {
      //int flags = fcntl(client_fd, F_GETFL, 0);
      //fcntl(client_fd, F_SETFL, flags | O_NONBLOCK);

      ProcessRequest(client_fd);
    }
  }
}

bool Server::AddRoute(const Request &request, const std::string_view &route, const RouteFunc &func) {
  std::string stringToHash = RequestToString(request) + route.data();
  uint64_t hash = Util::GenerateFNVHash(stringToHash);

  if (m_Routes.contains(hash)) // Request+Route already exists
    return false;

  Route rt = {
    .RequestType = request,
    .RouteString = route.data(),
    .Method = func
  };

  m_Routes.emplace(std::pair<uint64_t, Route>(hash, rt));
  return true;
}

void Server::SetHeader(const ResponseCode &code, const ResponseType &type) {
  m_Header.SetResponseCode(code);
  m_Header.SetResponseType(type);
}

std::string Server::ReadFullRequest(const int &fd) {
  std::string full_request;
  char buffer[4096];
  ssize_t bytes_received;

  bytes_received = read(fd, buffer, sizeof(buffer));
  if (bytes_received <= 0) return "";

  full_request.append(buffer, bytes_received);

  size_t header_end = full_request.find("\r\n\r\n");

  size_t content_length = 0;
  size_t cl_pos = full_request.find("Content-Length: ");
  if (cl_pos != std::string::npos) {
    content_length = std::stoi(full_request.substr(cl_pos + 16));
  }

  size_t body_already_read = (header_end != std::string::npos) 
    ? (full_request.length() - (header_end + 4)) : 0;

  while (body_already_read < content_length) {
    bytes_received = read(fd, buffer, sizeof(buffer));
    if (bytes_received <= 0) break;

    full_request.append(buffer, bytes_received);
    body_already_read += bytes_received;
  }

  return full_request;
}

void Server::ProcessRequest(const int &fd) {
  std::string requestStr = ReadFullRequest(fd);

  if (requestStr.length() <= 0) return;

  size_t spacePos = requestStr.find_first_of(" ");
  std::string requestTypeStr = requestStr.substr(0, spacePos);

  size_t currPos = spacePos + 1;
  spacePos = requestStr.find_first_of(" ", currPos);
  std::string routeStr = requestStr.substr(currPos, spacePos - currPos);

  uint64_t hash = Util::GenerateFNVHash(requestTypeStr + routeStr);
  if (!m_Routes.contains(hash)) {
    std::string message = "Page Not Found";
    SetHeader(ResponseCode::NotFound, ResponseType::TextPlain);
    m_Header.SetResponseLength(message.length());
    std::string response = "HTTP/1.1 " + m_Header.GetHeader() + message;
    send(fd, response.c_str(), response.size(), 0);
    close(fd);
    return;
  }

  currPos = requestStr.find("\r\n\r\n", spacePos); // This always exists
  std::string jsonData = requestStr.substr(currPos + 4);
  nlohmann::json data = nlohmann::json();
  if (!jsonData.empty())
    data = nlohmann::json::parse(jsonData);

  std::string message = m_Routes[hash].Method(data);
  m_Header.SetResponseLength(message.size());

  std::string response = "HTTP/1.1 " + m_Header.GetHeader() + message;

  send(fd, response.c_str(), response.size(), 0);
  close(fd);
}

}
