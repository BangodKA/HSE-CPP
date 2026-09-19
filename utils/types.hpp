#pragma once

namespace types {

void PrintSizes();

template<typename T>
concept HasMaxValues = std::integral<T> or std::floating_point<T>;

template<HasMaxValues T>
void PrintMaxVal();

}  // namespace types
