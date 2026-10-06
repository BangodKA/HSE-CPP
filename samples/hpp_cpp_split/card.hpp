#pragma once

#include <iostream>
#include <string>
#include <cstdint>

class Card {
friend std::ostream& operator<<(std::ostream& out, const Card& card);

public:
  Card() = default;

  explicit Card(std::string rarity, uint8_t level): rarity_(rarity), level_(level) {}

  uint8_t UpgradeLevel(uint8_t count);

  uint8_t GetLevel() const;

  static int number;

protected:
  std::string rarity_;
  uint8_t level_;
};