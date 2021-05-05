#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "basic.h"

class Human: public BasicPC {
  public:
    Human(int HP, int Atk, int Def, int Gold, std::string Name, bool compass, bool BS);
};

#endif
