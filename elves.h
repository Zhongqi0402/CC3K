

#ifndef _ELVES_H_
#define _ELVES_H_

#include "basic.h"

class Elves: public BasicPC {
  public:
    Elves(int HP, int Atk, int Def, int Gold, std::string Name, bool compass, bool BS);
};

#endif
