#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <functional>

class SequenceFinder {
 public:
  SequenceFinder();
  ~SequenceFinder();

  void findTheSequence(const std::vector<int8_t> haystack, std::vector<int8_t> needle,
                       uint32_t threshold, bool test_mode); // Based on vector template method "find"

  void findTheSequence2(const std::vector<int8_t> haystack, std::vector<int8_t> needle,
                       int32_t threshold, bool test_mode); // Based on cutting front elements in haystack

  void printMessage(uint32_t threshold, uint32_t haystackOffset, uint32_t needleOffset);
  
  bool preparator(const std::vector<int8_t> haystack, std::vector<int8_t> needle);
  void zeroFiller(std::vector<int8_t>& vec, int32_t offset, int32_t threshold);
  void shortVectorReset(std::vector<int8_t>& vec, int32_t offset, int32_t threshold, std::vector<int8_t>& shortVector);
  void shortVectorReset(std::vector<int8_t>::iterator it1, std::vector<int8_t>::iterator it2, std::vector<int8_t>& shortVector);
};
