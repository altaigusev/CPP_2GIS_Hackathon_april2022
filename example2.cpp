#include "file_reader.h"
#include "sequence_finder.h"

int main() {
  std::string haystackString =
      "vnk2435kvabco8awkh125kjneytbcd12qjhb4acd123xmnbqwnw4t";
  std::vector<int8_t> haystack(haystackString.begin(), haystackString.end());
  std::string needleString = "abcd1234";
  std::vector<int8_t> needle(needleString.begin(), needleString.end());
  uint32_t threshold = 3;

  SequenceFinder *Finder = new SequenceFinder();
  Finder->findTheSequence2(haystack, needle, threshold, true);

  return 0;
}
