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
      int flags = fcntl(client_fd, F_GETFL, 0);
      fcntl(client_fd, F_SETFL, flags | O_NONBLOCK);
      std::cout << "Connection Accepted!\n";
    }
  }
}

}
