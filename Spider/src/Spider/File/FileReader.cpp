#include "spch.h"
#include "FileReader.h"

namespace Spider {

std::string ReadFile(const std::filesystem::path &path) {
  std::ifstream in(path, std::ios::binary);

  if (!in)
    return "";

  std::string contents;
  in.seekg(0, std::ios::end);
  contents.resize(in.tellg());
  in.seekg(0, std::ios::beg);
  in.read(&contents[0], contents.size());
  in.close();
  return contents;
}

}
