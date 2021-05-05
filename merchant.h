#ifndef  _MERCHANT_H
#define _MERCHANT_H

#include<string>
#include "enemy.h"
#include <cmath>

// #include "pc.h"

class Merchant : public Enemy {

public:

	Merchant(int HP, int Atk, int Def, std::string Name, int Gold, bool move, bool compass);
	int Combat(PC* pc) override;
	~Merchant();
};

#endif
