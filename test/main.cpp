#include "Spider/Network/Server.h"

int main(void) {

  Spider::Server server = Spider::Server(8080);

  while (server.IsValid()) {
    server.Update();
  }
}
