#ifndef  _VAMPIRE_H
#define _VAMPIRE_H

#include<string>
#include "enemy.h"
#include <cmath>

// #include "pc.h"

class Vampire : public Enemy {

public:
	
	Vampire(int HP, int Atk, int Def, std::string Name, int Gold, bool move, bool compass);
	int Combat(PC* pc) override;
	~Vampire();
};

#endif
