#include "Spider/Network/Server.h"

int main(void) {

  Spider::Server server = Spider::Server(8080);

  server.AddRoute(Spider::Request::Get, "/", [](const nlohmann::json &data) -> std::string {
    return "Hello!";
  });

  while (server.IsValid()) {
    server.Update();
  }
}
