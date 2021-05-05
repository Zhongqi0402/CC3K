#include "basic.h"
#include <cmath>
#include "enemy.h"

BasicPC::BasicPC(int HP, int Atk, int Def, int Gold, std::string Name, bool compass, bool BS) 
  : PC{HP, Atk, Def, Gold, Name, compass, BS} {}


int BasicPC::Combat(Enemy *enemy) {
    
    srand(time(NULL));

    int random = rand() % 2;

    if (random == 0) {
        int pc_def = this->getDef();
        int enemy_atk = enemy->getAtk();
        int Damage = ceil(((double)100 / (double)(100 + pc_def)) * enemy_atk);
        if (this->BS == true) {
            this->setHP(this->getHP() - Damage / 2);
            return (double)Damage / (double)2;
        }
        else if (this->BS == false) {
            this->setHP(this->getHP() - Damage);
            return Damage;
        }
    }
    else {
        return 0;
    }
    return 0;
}
