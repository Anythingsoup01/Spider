#include "spch.h"
#include "Request.h"

namespace Spider {

Request ParseRequest(const std::string_view &requestStr) {
  if (requestStr == "GET") {
    return Request::Get;
  } else if (requestStr == "POST") {
    return Request::Post;
  } else if (requestStr == "PUT") {
    return Request::Put;
  } else if (requestStr == "DELETE") {
    return Request::Delete;
  } else if (requestStr == "HEAD") {
    return Request::Head;
  } else if (requestStr == "OPTIONS") {
    return Request::Options;
  } else if (requestStr == "PATCH") {
    return Request::Patch;
  } else if (requestStr == "TRACE") {
    return Request::Trace;
  } else if (requestStr == "CONNECT") {
    return Request::Connect;
  }

  return Request::Unknown;
}

}
