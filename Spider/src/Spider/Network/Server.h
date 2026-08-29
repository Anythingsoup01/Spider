#pragma once

#include "Request.h"
#include <nlohmann/json.hpp>

namespace Spider {

using RouteFunc = std::function<std::string(const nlohmann::json &)>;

class Server {
public:
  // Creates a socket on the provided port.
  // Check IsValid() before using.
  Server(const uint16_t &port);

  // Closes the socket if it was successfully created.
  ~Server();

  // If the socket was successfully created and bound
  const bool &IsValid() const { return m_IsValid; }

  // Polls the server for connections and requests
  void Update();

  // Adds a route to the server for web requests
  bool AddRoute(const Request &request, const std::string_view &route, const RouteFunc &func);
private:
  // Reads the entire web request until the end "CRCR" (\r\n\r\n)
  std::string ReadFullRequest(const int &fd);

  void ProcessRequest(const int &fd);
private:
  struct Route {
    Request RequestType;
    std::string RouteString;
    RouteFunc Method;
  };
private:
  int m_FD = -1;
  bool m_IsValid = false;

  std::unordered_map<uint64_t, Route> m_Routes;
};

}
