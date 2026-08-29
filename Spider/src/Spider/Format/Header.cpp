#include "spch.h"
#include "Header.h"

namespace Spider {

std::string FormatHeader::GetHeader() {
  return ResponseCodeToString(m_Code) +
         "\r\nContent-Length: " + std::to_string(m_Length) + "\r\n" +
         ResponseTypeToString(m_Type) + "\r\n\r\n";
}

std::string FormatHeader::ResponseCodeToString(const ResponseCode &code) {
  switch (code) {
  // 1xx
  case ResponseCode::Continue:
    return "100 Continue";
  case ResponseCode::SwitchingProtocols:
    return "101 Switching Protocols";
  case ResponseCode::Processing:
    return "102 Processing";
  case ResponseCode::EarlyHints:
    return "103 Early Hints";

  // 2xx
  case ResponseCode::OK:
    return "200 OK";
  case ResponseCode::Created:
    return "201 Created";
  case ResponseCode::Accepted:
    return "202 Accepted";
  case ResponseCode::NoContent:
    return "204 No Content";
  case ResponseCode::PartialContent:
    return "206 Partial Content";

  // 3xx
  case ResponseCode::MovedPermanently:
    return "301 Moved Permanently";
  case ResponseCode::Found:
    return "302 Found";
  case ResponseCode::SeeOther:
    return "303 See Other";
  case ResponseCode::NotModified:
    return "304 Not Modified";
  case ResponseCode::TemporaryRedirect:
    return "307 Temporary Redirect";
  case ResponseCode::PermanentRedirect:
    return "308 Permanent Redirect";

  // 4xx
  case ResponseCode::BadRequest:
    return "400 Bad Request";
  case ResponseCode::Unauthorized:
    return "401 Unauthorized";
  case ResponseCode::Forbidden:
    return "403 Forbidden";
  case ResponseCode::NotFound:
    return "404 Not Found";
  case ResponseCode::MethodNotAllowed:
    return "405 Method Not Allowed";
  case ResponseCode::RequestTimeout:
    return "408 Request Timeout";
  case ResponseCode::Conflict:
    return "409 Conflict";
  case ResponseCode::Gone:
    return "410 Gone";
  case ResponseCode::UnsupportedMediaType:
    return "415 Unsupported Media Type";
  case ResponseCode::UnprocessableEntity:
    return "422 Unprocessable Entity";
  case ResponseCode::TooManyRequests:
    return "429 Too Many Requests";

  // 5xx
  case ResponseCode::InternalServerError:
    return "500 Internal Server Error";
  case ResponseCode::NotImplemented:
    return "501 Not Implemented";
  case ResponseCode::BadGateway:
    return "502 Bad Gateway";
  case ResponseCode::ServiceUnavailable:
    return "503 Service Unavailable";
  case ResponseCode::GatewayTimeout:
    return "504 Gateway Timeout";

  default:
    return "Unknown Status Code";
  }
}

std::string FormatHeader::ResponseTypeToString(const ResponseType &type) {
  switch (type) {
  // Application
  case ResponseType::ApplicationJson:
    return "application/json";
  case ResponseType::ApplicationXml:
    return "application/xml";
  case ResponseType::ApplicationFormUrlEncoded:
    return "application/x-www-form-urlencoded";
  case ResponseType::ApplicationOctetStream:
    return "application/octet-stream";
  case ResponseType::ApplicationPdf:
    return "application/pdf";
  case ResponseType::ApplicationZip:
    return "application/zip";
  case ResponseType::ApplicationJavascript:
    return "application/javascript";

  // Text
  case ResponseType::TextPlain:
    return "text/plain";
  case ResponseType::TextHtml:
    return "text/html";
  case ResponseType::TextCss:
    return "text/css";
  case ResponseType::TextJavascript:
    return "text/javascript";
  case ResponseType::TextXml:
    return "text/xml";
  case ResponseType::TextCsv:
    return "text/csv";

  // Image
  case ResponseType::ImagePng:
    return "image/png";
  case ResponseType::ImageJpeg:
    return "image/jpeg";
  case ResponseType::ImageGif:
    return "image/gif";
  case ResponseType::ImageSvg:
    return "image/svg+xml";
  case ResponseType::ImageWebp:
    return "image/webp";
  case ResponseType::ImageIco:
    return "image/x-icon";

  // Multipart
  case ResponseType::MultipartFormData:
    return "multipart/form-data";
  case ResponseType::MultipartByteranges:
    return "multipart/byteranges";

  // Audio / Video
  case ResponseType::AudioMpeg:
    return "audio/mpeg";
  case ResponseType::AudioOgg:
    return "audio/ogg";
  case ResponseType::VideoMp4:
    return "video/mp4";
  case ResponseType::VideoWebm:
    return "video/webm";

  default:
    return "application/octet-stream";
  }
}

} // namespace Spider
