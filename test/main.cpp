#include "Spider/Format/Header.h"
#include "Spider/Network/Server.h"
#include "Spider/File/FileReader.h"

// When using a server outside a class, it must be static to set the headers
static Spider::Server s_Server(8080);

std::string RootRoute(const nlohmann::json &data) {
  s_Server.SetHeader(Spider::ResponseCode::OK, Spider::ResponseType::TextHtml);
  return Spider::ReadFile("resources/index.html");
}

std::string StyleRoute(const nlohmann::json &data) {
  s_Server.SetHeader(Spider::ResponseCode::OK, Spider::ResponseType::TextCss);
  return Spider::ReadFile("resources/style.css");
}

std::string JScriptRoute(const nlohmann::json &data) {
  s_Server.SetHeader(Spider::ResponseCode::OK, Spider::ResponseType::ApplicationJavascript);
  return Spider::ReadFile("resources/script.js");
}

std::string SubmissionRoute(const nlohmann::json &data) {
  s_Server.SetHeader(Spider::ResponseCode::OK, Spider::ResponseType::ApplicationJson);

  return std::string();
}

int main(void) {
  s_Server.AddRoute(Spider::Request::Get, "/", RootRoute);
  s_Server.AddRoute(Spider::Request::Get, "/style.css", StyleRoute);
  s_Server.AddRoute(Spider::Request::Get, "/script.js", JScriptRoute);
  s_Server.AddRoute(Spider::Request::Post, "/submission", SubmissionRoute);
  while (s_Server.IsValid()) {
    s_Server.Update();
  }
}
