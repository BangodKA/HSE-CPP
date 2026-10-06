#include "card.hpp"

std::ostream& operator<<(std::ostream& out, const Card& card) {
  out << card.rarity_ << " " << static_cast<int>(card.level_) << std::endl;

  return out;
}

uint8_t Card::UpgradeLevel(uint8_t count) {
    level_ += count;
    return level_; // this->level (*this).level
}

uint8_t Card::GetLevel() const {
    return level_;
}

int Card::number = 10;
