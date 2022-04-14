#include <chrono>
#include <iostream>

#include "file_reader.h"
#include "sequence_finder.h"

int main() {
  FileReader haystackFile("big_haystack.txt");
  FileReader needleFile("big_needle.txt");
  uint32_t threshold = 3;

  std::vector<int8_t> haystack = haystackFile.getVectorFromFile();
  std::vector<int8_t> needle = needleFile.getVectorFromFile();

  SequenceFinder *Finder = new SequenceFinder();

  std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
  start = std::chrono::high_resolution_clock::now();
  Finder->findTheSequence(haystack, needle, threshold, true);
  end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> duration = end - start;
  std::cout << "Code Duration " << duration.count() << std::endl;


  start = std::chrono::high_resolution_clock::now();
  Finder->findTheSequence2(haystack, needle, threshold, true);
  end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration2 = end - start;
  std::cout << "Code Duration " << duration.count() << std::endl;

  if (duration < duration2) {
    std::cout << "Algorithm 1 more efficient" << std::endl;
  } else if (duration > duration2) {
    std::cout << "Algorithm 2 more efficient" << std::endl;
  } else {
    std::cout << "Algorithms are equal" << std::endl;
  }
  delete Finder;
  return 0;
}