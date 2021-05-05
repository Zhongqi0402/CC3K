#include "decorator.h"



AbstractPotion::AbstractPotion(int HP, int Atk, int Def, std::string Name)
  : HP{HP}, Atk{Atk}, Def{Def}, Name{Name} {}

int AbstractPotion::getHP() { return HP; }

int AbstractPotion::getAtk() { return Atk; }

int AbstractPotion::getDef() { return Def; }

std::string AbstractPotion::getName() { return Name; }

AbstractPotion::~AbstractPotion() { }
