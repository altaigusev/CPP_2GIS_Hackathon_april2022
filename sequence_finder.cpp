#include "sequence_finder.h"

SequenceFinder::SequenceFinder() {}

SequenceFinder::~SequenceFinder() {}

void SequenceFinder::findTheSequence(const std::vector<int8_t> haystack,
                                     std::vector<int8_t> needle,
                                     uint32_t threshold, bool test_mode) {
  if (!test_mode) {
    if (!preparator(haystack, needle)) {
      throw std::out_of_range(
          "Bad data - size of haystack or needle does not correspond to the "
          "task");
    }
  }
  std::vector<int8_t> shadow_haystack;
  std::copy(haystack.begin(), haystack.end(),
            std::back_inserter(shadow_haystack));

  uint32_t needleOffset = 0;
  uint32_t haystackOffset = 0;
  uint32_t threshold_start = threshold;
  bool isPreviousCoincidence = 0;

  std::vector<int8_t> shortNeedle;
  shortVectorReset(needle, needleOffset, threshold_start, shortNeedle);
  std::vector<int8_t> shortHaystack;
  std::vector<int8_t>::iterator it = std::find(
      shadow_haystack.begin(), shadow_haystack.end(), shortNeedle.at(0));

  while (threshold + needleOffset < needle.size()) {
    it = std::find(shadow_haystack.begin(), shadow_haystack.end(),
                   shortNeedle.at(0));
    while (it != shadow_haystack.end()) {
      haystackOffset = it - shadow_haystack.begin();
      shortVectorReset(it, it + threshold, shortHaystack);
      while (shortHaystack == shortNeedle) {
        isPreviousCoincidence = true;
        shortVectorReset(needle, needleOffset, threshold, shortNeedle);
        shortVectorReset(it, it + threshold, shortHaystack);

        if (shortHaystack == shortNeedle) {
          if (threshold + needleOffset < needle.size())
            ++threshold;
          else
            break;
        } else {
          break;
        }
      }
      if (isPreviousCoincidence) {
        --threshold;
        printMessage(threshold, haystackOffset, needleOffset);
        isPreviousCoincidence = false;
        zeroFiller(shadow_haystack, haystackOffset, threshold);
      }
      it = std::find(shadow_haystack.begin() + haystackOffset + 1,
                     shadow_haystack.end(), shortNeedle.at(0));
      threshold = threshold_start;
      shortVectorReset(needle, needleOffset, threshold, shortNeedle);
    }
    ++needleOffset;
    threshold = threshold_start;
    shortVectorReset(needle, needleOffset, threshold, shortNeedle);
  }
}

void SequenceFinder::findTheSequence2(const std::vector<int8_t> haystack,
                                      std::vector<int8_t> needle,
                                      int32_t threshold, bool test_mode) {
  if (!test_mode) {
    if (!preparator(haystack, needle)) {
      throw std::out_of_range(
          "Bad data - size of haystack or needle does not correspond to the "
          "task");
    }
  }
  int32_t needleSize = needle.size();
  int32_t needleOffset = 0;
  int32_t haystackOffset = 0;
  int32_t threshold_start = threshold;
  bool isPreviousCoincidence = 0;
  std::vector<int8_t> shortNeedle;
  std::vector<int8_t> shortHaystack;
  std::vector<int8_t> shadow_haystack;
  std::copy(haystack.begin(), haystack.end(),
            std::back_inserter(shadow_haystack));
  while (shadow_haystack.size() >= threshold) {
    shortVectorReset(shadow_haystack, 0, threshold, shortHaystack);
    while (shortHaystack != shortNeedle &&
           needleOffset + threshold <= needleSize) {
      shortVectorReset(needle, needleOffset, threshold, shortNeedle);
      if (shortNeedle != shortHaystack) {
        ++needleOffset;
      }
    }
    bool needle_overflow = false;
    while (shortHaystack == shortNeedle &&
           needleOffset + threshold <= needleSize &&
           shadow_haystack.size() > threshold) {
      isPreviousCoincidence = true;
      ++threshold;
      if (threshold >= needleSize) {
        needle_overflow = true;
        --threshold;
        break;
      }
      shortVectorReset(shadow_haystack, 0, threshold, shortHaystack);
      shortVectorReset(needle, needleOffset, threshold, shortNeedle);
    }
    if (isPreviousCoincidence) {
      if(!needle_overflow) {
         --threshold;
         needle_overflow = false;
      }
      printMessage(threshold, haystackOffset, needleOffset);
      isPreviousCoincidence = false;
      shadow_haystack.erase(shadow_haystack.begin(),
                            shadow_haystack.begin() + threshold);
      haystackOffset += threshold;
    }
    threshold = threshold_start;
    shadow_haystack.erase(shadow_haystack.begin());
    ++haystackOffset;
    needleOffset = 0;
  }
}

bool SequenceFinder::preparator(const std::vector<int8_t> haystack,
                                std::vector<int8_t> needle) {
  if (needle.size() < 1000 || needle.size() > 1e6) return false;
  if (haystack.size() < needle.size()) return false;
  return true;
}

void SequenceFinder::zeroFiller(std::vector<int8_t>& vec, int32_t offset,
                                int32_t threshold) {
  auto start = vec.begin() + offset;
  auto end = vec.begin() + offset + threshold;
  for (auto iter = start; iter != end; ++iter) {
    iter[0] = 0;
  }
}

void SequenceFinder::shortVectorReset(std::vector<int8_t>& vec, int32_t offset,
                                      int32_t threshold,
                                      std::vector<int8_t>& shortVector) {
  shortVector.clear();
  std::copy(vec.begin() + offset, vec.begin() + offset + threshold,
            std::back_inserter(shortVector));
}

void SequenceFinder::shortVectorReset(std::vector<int8_t>::iterator it1,
                                      std::vector<int8_t>::iterator it2,
                                      std::vector<int8_t>& shortVector) {
  shortVector.clear();
  std::copy(it1, it2, std::back_inserter(shortVector));
}

void SequenceFinder::printMessage(uint32_t threshold, uint32_t haystackOffset,
                                  uint32_t needleOffset) {
  std::cout << "sequence of length = " << threshold
            << " found at haystack offset " << haystackOffset
            << ", needle offset " << needleOffset << std::endl;
}
