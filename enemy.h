#ifndef  _ENEMY_H
#define _ENEMY_H

#include <string>
#include "pc.h"

class PC;
class Enemy {

	int HP;
	int Atk;
	int Def;
	std::string Name;
	int Gold;
	bool move;
	bool compass;

protected:

	void setHP(int HP);

public:

	int getHP() const;
	int getAtk() const;
	int getDef()const ;
	int getGold() const;
	std::string getName() const;
	bool getMove() const;
	void setMove(bool move);
	void setCompass(bool compass);
	bool getCompass();
	Enemy(int HP, int Atk, int Def, std::string Name, int Gold, bool move, bool compass);
	virtual int Combat(PC* pc) = 0;
	virtual ~Enemy();
};

#endif
