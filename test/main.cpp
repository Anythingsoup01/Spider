#include "Spider/Format/Header.h"
#include "Spider/Network/Server.h"
#include "Spider/File/FileReader.h"

// When using a server outside a class, it must be static to set the headers
static Spider::Server s_Server(8080);

std::string SubmissionRoute(const nlohmann::json &data) {
  s_Server.SetHeader(Spider::ResponseCode::OK, Spider::ResponseType::ApplicationJson);

  std::string user = "NULL";
  if (data.contains("username")) {
    user = data["username"];
  }

  std::string out = "{\"message\": \"" + user + "\"}";

  return out;

}

int main(void) {
  s_Server.SetResourceDirectory("resources", true);
  s_Server.AddRoute(Spider::Request::Post, "/submission", SubmissionRoute);
  while (s_Server.IsValid()) {
    s_Server.Update();
  }
}
