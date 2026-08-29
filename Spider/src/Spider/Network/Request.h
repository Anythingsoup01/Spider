#pragma once

namespace Spider {

enum class Request : uint8_t {
  Unknown = 0,
  Get,
  Post,
  Put,
  Delete,
  Head,
  Options,
  Patch,
  Trace,
  Connect,
};

Request ParseRequest(const std::string_view &requestStr);

std::string RequestToString(const Request &request);

}
