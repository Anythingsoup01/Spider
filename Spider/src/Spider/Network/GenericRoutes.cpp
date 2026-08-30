#include "spch.h"
#include "GenericRoutes.h"

#include "Spider/File/FileReader.h"

namespace Spider {

std::string GenericApplicationJson(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::ApplicationJson);
  return ReadFile(filePath);
}

std::string GenericApplicationXml(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::ApplicationXml);
  return ReadFile(filePath);
}

std::string GenericApplicationFormUrlEncoded(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::ApplicationFormUrlEncoded);
  return ReadFile(filePath);
}

std::string GenericApplicationOctetStream(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::ApplicationOctetStream);
  return ReadFile(filePath);
}

std::string GenericApplicationPdf(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::ApplicationPdf);
  return ReadFile(filePath);
}

std::string GenericApplicationZip(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::ApplicationZip);
  return ReadFile(filePath);
}

std::string GenericApplicationJavascript(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::ApplicationJavascript);
  return ReadFile(filePath);
}

std::string GenericTextPlain(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::TextPlain);
  return ReadFile(filePath);
}

std::string GenericTextHtml(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::TextHtml);
  return ReadFile(filePath);
}

std::string GenericTextCss(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::TextCss);
  return ReadFile(filePath);
}

std::string GenericTextJavascript(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::TextJavascript);
  return ReadFile(filePath);
}

std::string GenericTextXml(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::TextXml);
  return ReadFile(filePath);
}

std::string GenericTextCsv(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::TextCsv);
  return ReadFile(filePath);
}

std::string GenericImagePng(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::ImagePng);
  return ReadFile(filePath);
}

std::string GenericImageJpeg(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::ImageJpeg);
  return ReadFile(filePath);
}

std::string GenericImageGif(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::ImageGif);
  return ReadFile(filePath);
}

std::string GenericImageSvg(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::ImageSvg);
  return ReadFile(filePath);
}

std::string GenericImageWebp(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::ImageWebp);
  return ReadFile(filePath);
}

std::string GenericImageIco(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::ImageIco);
  return ReadFile(filePath);
}

std::string GenericMultipartFormData(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::MultipartFormData);
  return ReadFile(filePath);
}

std::string GenericMultipartByteranges(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::MultipartByteranges);
  return ReadFile(filePath);
}

std::string GenericAudioMpeg(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::AudioMpeg);
  return ReadFile(filePath);
}

std::string GenericAudioOgg(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::AudioOgg);
  return ReadFile(filePath);
}

std::string GenericVideoMp4(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::VideoMp4);
  return ReadFile(filePath);
}

std::string GenericVideoWebm(Server *server, const std::filesystem::path &filePath) {
  server->SetHeader(ResponseCode::OK, ResponseType::VideoWebm);
  return ReadFile(filePath);
}

}
