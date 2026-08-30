#pragma once

#include "Server.h"

namespace Spider {

// Application Types
std::string GenericApplicationJson(Server *server, const std::filesystem::path &filePath);
std::string GenericApplicationXml(Server *server, const std::filesystem::path &filePath);
std::string GenericApplicationFormUrlEncoded(Server *server, const std::filesystem::path &filePath);
std::string GenericApplicationOctetStream(Server *server, const std::filesystem::path &filePath);
std::string GenericApplicationPdf(Server *server, const std::filesystem::path &filePath);
std::string GenericApplicationZip(Server *server, const std::filesystem::path &filePath);
std::string GenericApplicationJavascript(Server *server, const std::filesystem::path &filePath);

// Text Types
std::string GenericTextPlain(Server *server, const std::filesystem::path &filePath);
std::string GenericTextHtml(Server *server, const std::filesystem::path &filePath);
std::string GenericTextCss(Server *server, const std::filesystem::path &filePath);
std::string GenericTextJavascript(Server *server, const std::filesystem::path &filePath);
std::string GenericTextXml(Server *server, const std::filesystem::path &filePath);
std::string GenericTextCsv(Server *server, const std::filesystem::path &filePath);

// Image Types
std::string GenericImagePng(Server *server, const std::filesystem::path &filePath);
std::string GenericImageJpeg(Server *server, const std::filesystem::path &filePath);
std::string GenericImageGif(Server *server, const std::filesystem::path &filePath);
std::string GenericImageSvg(Server *server, const std::filesystem::path &filePath);
std::string GenericImageWebp(Server *server, const std::filesystem::path &filePath);
std::string GenericImageIco(Server *server, const std::filesystem::path &filePath);

// Multipart Types
std::string GenericMultipartFormData(Server *server, const std::filesystem::path &filePath);
std::string GenericMultipartByteranges(Server *server, const std::filesystem::path &filePath);

// Audio & Video
std::string GenericAudioMpeg(Server *server, const std::filesystem::path &filePath);
std::string GenericAudioOgg(Server *server, const std::filesystem::path &filePath);
std::string GenericVideoMp4(Server *server, const std::filesystem::path &filePath);
std::string GenericVideoWebm(Server *server, const std::filesystem::path &filePath);

}
