#ifndef  _GOBLIN_H
#define _GOBLIN_H

#include<string>
#include "enemy.h"
#include <cmath>

// #include "pc.h"

class Goblin : public Enemy {

public:

	Goblin(int HP, int Atk, int Def, std::string Name, int Gold, bool move, bool compass);
	int Combat(PC* pc) override;
	~Goblin();
};

#endif
