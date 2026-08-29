#include "Spider/Format/Header.h"
#include "Spider/Network/Server.h"

class test {
public:
  test() {
    // When using a server inside a class 'this' must be passed into the lambda
    m_Server.AddRoute(Spider::Request::Get, "/",
      [this](const nlohmann::json &data) -> std::string {
      m_Server.SetHeader(Spider::ResponseCode::OK, Spider::ResponseType::TextPlain);

      return "This text is plain!";
    });
  }

  ~test() = default;

  void Update() {
    if (m_Server.IsValid())
      m_Server.Update();
  }

private:
  Spider::Server m_Server = Spider::Server(8080);
};

int main(void) {
  // When using a server outside a class, it must be static to set the headers
  static Spider::Server server = Spider::Server(8080);
  server.AddRoute(Spider::Request::Get, "/",
                  [](const nlohmann::json &data) -> std::string {
                    server.SetHeader(Spider::ResponseCode::OK,
                                     Spider::ResponseType::TextPlain);

                    return "This text is plain!";
                  });

  while (server.IsValid()) {
    server.Update();
  }
}
