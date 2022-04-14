#include "file_reader.h"

FileReader::FileReader() {}

FileReader::FileReader(const std::string filename) : _filename(filename) {}

FileReader::~FileReader() {}

std::vector<int8_t> FileReader::getVectorFromFile() {
  std::ifstream file(_filename, std::ios::binary);
  std::streampos fileSize;
  std::vector<int8_t> fileBinaryContent;
  file.seekg(0, std::ios::end);
  fileSize = file.tellg();
  file.seekg(0, std::ios::beg);

  fileBinaryContent.reserve(fileSize);

  fileBinaryContent.insert(fileBinaryContent.begin(),
                           std::istream_iterator<int8_t>(file),
                           std::istream_iterator<int8_t>());

  return fileBinaryContent;
}