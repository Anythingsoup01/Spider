#pragma once

namespace Spider {

enum class ResponseCode : uint16_t {
  Unknown = 0,
  // 1xx Informational
  Continue = 100,
  SwitchingProtocols = 101,
  Processing = 102,
  EarlyHints = 103,

  // 2xx Success
  OK = 200,
  Created = 201,
  Accepted = 202,
  NoContent = 204,
  PartialContent = 206,

  // 3xx Redirection
  MovedPermanently = 301,
  Found = 302,
  SeeOther = 303,
  NotModified = 304,
  TemporaryRedirect = 307,
  PermanentRedirect = 308,

  // 4xx Client Errors
  BadRequest = 400,
  Unauthorized = 401,
  Forbidden = 403,
  NotFound = 404,
  MethodNotAllowed = 405,
  RequestTimeout = 408,
  Conflict = 409,
  Gone = 410,
  UnsupportedMediaType = 415,
  UnprocessableEntity = 422,
  TooManyRequests = 429,

  // 5xx Server Errors
  InternalServerError = 500,
  NotImplemented = 501,
  BadGateway = 502,
  ServiceUnavailable = 503,
  GatewayTimeout = 504
};

enum class ResponseType : uint8_t {
  Unknown = 0,
  // Application Types
  ApplicationJson,
  ApplicationXml,
  ApplicationFormUrlEncoded,
  ApplicationOctetStream,
  ApplicationPdf,
  ApplicationZip,
  ApplicationJavascript,

  // Text Types
  TextPlain,
  TextHtml,
  TextCss,
  TextJavascript,
  TextXml,
  TextCsv,

  // Image Types
  ImagePng,
  ImageJpeg,
  ImageGif,
  ImageSvg,
  ImageWebp,
  ImageIco,

  // Multipart Types
  MultipartFormData,
  MultipartByteranges,

  // Audio & Video
  AudioMpeg,
  AudioOgg,
  VideoMp4,
  VideoWebm
};

class FormatHeader {
public:
  FormatHeader() = default;

  void SetResponseCode(const ResponseCode &code) { m_Code = code; }

  void SetResponseLength(const size_t &length) { m_Length = length; }

  void SetResponseType(const ResponseType &type) { m_Type = type; }

  std::string GetHeader();

private:
  std::string ResponseCodeToString(const ResponseCode &code);

  std::string ResponseTypeToString(const ResponseType &type);

private:
  ResponseCode m_Code;
  size_t m_Length;
  ResponseType m_Type;
};

} // namespace Spider
