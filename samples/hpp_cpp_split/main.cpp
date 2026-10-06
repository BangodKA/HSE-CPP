#include "card.hpp"
#include <cstdint>
#include <iostream>
#include <string>

class Alive : public Card {
public:
  Alive(std::string rarity, uint8_t level, uint32_t hp) 
  : Card(rarity, level), hp_(hp) {}

  ~Alive() = default;

  void DecreaseHp(uint32_t d) {
    if (d >= hp_){
      hp_ = 0;
      return;
    }
    hp_ -= d;
  }
private: 
  uint32_t hp_;
};

class Building : public Alive {
public:
  Building(std::string rarity, uint8_t level, uint32_t ttl, uint32_t hp) 
    : Alive(rarity, level, hp), ttl_(ttl) {} 

  ~Building() = default;

private:
  [[maybe_unused]] uint32_t ttl_;
};

class Unit : public Alive {
public:
  Unit(std::string rarity, uint8_t level, uint32_t hp, uint32_t damage, uint32_t range) 
    : Alive(rarity, level, hp), damage_(damage), range_(range) {} 

  ~Unit() = default;

  void Attack(Alive& target, const uint32_t distance) {
    if (distance <= range_) {
      target.DecreaseHp(damage_);
    }
  }
private:
  uint32_t damage_;
  uint32_t range_;
};

int main() {

  Card mega_knight = Card{"legendary", 100};
  Card elite_barbarian = Card{"common", 10};
  std::cout << mega_knight << mega_knight.number << std::endl;
  std::cout << elite_barbarian << elite_barbarian.number << std::endl;

  mega_knight.UpgradeLevel(11);
  ++mega_knight.number; // ++Card::number

  std::cout << mega_knight << mega_knight.number << std::endl;
  std::cout << elite_barbarian << elite_barbarian.number << std::endl;
  // mega_knight.operator<<(std::cout)<< std::endl;
  // operator<<(operator<<())
  return 0;
}
