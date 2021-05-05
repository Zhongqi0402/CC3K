#ifndef  _TROLL_H
#define _TROLL_H

#include<string>
#include "enemy.h"
#include <cmath>

// #include "pc.h"

class Troll : public Enemy {

public:

	Troll(int HP, int Atk, int Def, std::string Name, int Gold, bool move, bool compass);
	int Combat(PC* pc) override;
	~Troll();
};

#endif
