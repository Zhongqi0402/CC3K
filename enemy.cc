#include "enemy.h"

int Enemy::getHP() const{
	return HP;
}

int Enemy::getAtk() const{
	return Atk;
}

int Enemy::getDef() const {
	return Def;
}

int Enemy::getGold() const {
	return Gold;
}

bool Enemy::getCompass() {
	return compass;
}
std::string Enemy::getName() const {
	return Name;
}

bool Enemy::getMove() const {
	return move;
}

void Enemy::setMove(bool move) {
	this->move = move;
}

void Enemy::setHP(int HP) {
	
	if (HP > 0) {
		this->HP = HP;
	}
	else {
		this->HP = 0;
	}
}

void Enemy::setCompass(bool compass) {
	this->compass = compass;
}

Enemy::Enemy(int HP, int Atk, int Def, std::string Name, int Gold, bool move, bool compass) : HP{HP}, Atk{Atk}, Def{Def},
Name{ Name }, Gold{ Gold }, move{ move }, compass{ compass } {}

Enemy::~Enemy() {};
