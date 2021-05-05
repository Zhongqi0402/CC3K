#ifndef _BASIC_H_
#define _BASIC_H_

#include "pc.h"

class Enemy;

class BasicPC : public PC {
  public:
    BasicPC(int HP, int Atk, int Def, int Gold, std::string Name, bool compass, bool BS);
    int Combat(Enemy *enemy) override;
};

#endif
