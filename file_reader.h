#pragma once

#include <fstream>
#include <vector>
#include <iterator>

class FileReader {
  private:
    std::string _filename;

  public:
  FileReader();
  FileReader(const std::string filename);
  ~FileReader();
  std::vector<int8_t> getVectorFromFile();
};
