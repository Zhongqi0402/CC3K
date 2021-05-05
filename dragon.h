#ifndef  _DRAGON_H
#define _DRAGON_H

#include<string>
#include "enemy.h"
#include <cmath>

// #include "pc.h"

class Dragon : public Enemy {

public:

	Dragon(int HP, int Atk, int Def, std::string Name, int Gold, bool move, bool compass);
	int Combat(PC* pc) override;
	~Dragon();
};

#endif
