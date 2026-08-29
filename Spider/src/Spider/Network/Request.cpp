#include "Request.h"
#include "spch.h"

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

std::string RequestToString(const Request &request) {
  switch (request) {
    case Request::Get:      return "GET";
    case Request::Post:     return "POST";
    case Request::Put:      return "PUT";
    case Request::Delete:   return "DELETE";
    case Request::Head:     return "HEAD";
    case Request::Options:  return "OPTIONS";
    case Request::Patch:    return "PATCH";
    case Request::Trace:    return "TRACE";
    case Request::Connect:  return "CONNECT";
    default:  return "UNKNOWN";
  }
}

} // namespace Spider
