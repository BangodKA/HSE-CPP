#include <bitset>
#include <iomanip>
#include <iostream>
#include <bit>

#include "float.hpp"

namespace float_ns {

void ReprFloatNaive(float num) {
  std::cout << std::bitset<sizeof(float)*CHAR_BIT>(num) << std::endl;
}

// -> 1
// 2
// 3
// 4

void ReprFloatInBinaryWithChar(float num) {
  char* const num_addr = reinterpret_cast<char*>(&num);
  for (size_t i = sizeof(float); i > 0; --i) {
    std::cout << std::bitset<8>(*(num_addr + (i - 1)));
  }
  std::cout << std::endl;
}

void ReprFloatInBinaryCool(float num) {
  std::cout << std::bitset<sizeof(float)*CHAR_BIT>(std::bit_cast<uint32_t>(num));
}

void ReprUintInBinaryWithChar(int num) {
  char* const num_addr = reinterpret_cast<char*>(&num);
  // for (size_t i = sizeof(float); i > 0; --i) {
  //   std::cout << std::bitset<8>(num_addr[i - 1]);
  // }
  for (size_t i = 0; i < sizeof(int); ++i) {
    std::cout << std::bitset<8>(num_addr[i]) << " ";
  }
}

void PrintFloatInfo(float num) {
    std::cout << std::fixed
            << std::setprecision(6)
            << num
            << " " << static_cast<uint32_t>(num);
}

void ReprNConsFloats(float start, int count) {
  for (int i = 0; i < count; ++i) {
    float_ns::ReprFloatInBinaryCool(start + i);
    std::cout << std::endl;
  }
}

void InfNan() {
  float zero {0.0};
  float posinf { 5.0f / zero }; // positive infinity
  std::cout << posinf << '\n';
  ReprFloatInBinaryCool(posinf);
  std::cout << std::endl;

  float neginf { -5.0f / zero }; // negative infinity
  std::cout << neginf << " " << '\n';
  ReprFloatInBinaryCool(neginf);
  std::cout << std::endl;

  float nan { zero / zero }; // not a number (mathematically invalid)
  std::cout << nan << " " <<'\n';
  ReprFloatInBinaryCool(nan);
  std::cout << std::endl;
}

}
