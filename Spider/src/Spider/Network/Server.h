#pragma once

#include <nlohmann/json.hpp>

#include "Request.h"
#include "Spider/Format/Header.h"

namespace Spider {

class Server;

using RouteFunc = std::function<std::string(const nlohmann::json &)>;
using GenericRouteFunc = std::function<std::string(Server *, const std::filesystem::path &)>;

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

  // Locates the given file in the resource directory and hosts it,
  //  to utilized with other resource files you will only need to
  //  use the relative path from the resource path.
  bool HostFile(const std::filesystem::path &filePath, const std::string &routeOverride = std::string());

  // Sets the header for the next loaded file / payload to tell Spider
  // if there was an error and how to properly load the data
  void SetHeader(const ResponseCode &code, const ResponseType &type);

  // Sets the directory for the resource folder for easy file hosting
  void SetResourceDirectory(const std::filesystem::path &path) { m_ResourceDirectory = path; }
private:
  // Reads the entire web request until the end
  std::string ReadFullRequest(const int &fd);

  // Processes and calls backend methods if request route is registered
  void ProcessRequest(const int &fd);
private:
  struct Route {
    Request RequestType;
    std::string RouteString;
    RouteFunc Method;

    std::filesystem::path FilePath; // Used in conjunction with GenericMethod | NOT USED FOR ANYTHING ELSE
    GenericRouteFunc GenericMethod;
  };
private:
  int m_FD = -1;
  bool m_IsValid = false;
  std::filesystem::path m_ResourceDirectory;

  FormatHeader m_Header;

  std::unordered_map<uint64_t, Route> m_Routes;
};

}
