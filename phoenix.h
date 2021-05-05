#ifndef  _PHOENIX_H
#define _PHOENIX_H

#include<string>
#include "enemy.h"
#include <cmath>

// #include "pc.h"

class Phoenix : public Enemy {

public:

	Phoenix(int HP, int Atk, int Def, std::string Name, int Gold, bool move, bool compass);
	int Combat(PC* pc) override;
	~Phoenix();
};

#endif
