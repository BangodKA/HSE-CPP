#pragma once

#include <iostream>

namespace templates {
template <class Arg>
concept Integral = std::is_same_v<int, Arg> || std::is_same_v<long long, Arg>;

template <class Arg>
void Print(Arg&& name) requires std::is_same_v<int, Arg> || std::is_same_v<long long, Arg> {
  std::cout << name << std::endl;
}

} // namespace templates
