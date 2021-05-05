#ifndef  _WEREWOLF_H
#define _WEREWOLF_H

#include<string>
#include "enemy.h"
#include <cmath>

// #include "pc.h"

class Werewolf : public Enemy {

public:

	Werewolf(int HP, int Atk, int Def, std::string Name, int Gold, bool move, bool compass);
	int Combat(PC* pc) override;
	~Werewolf();
};

#endif
