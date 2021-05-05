// orc.h

#ifndef _ORC_H_
#define _ORC_H_

#include "basic.h"

class Orc: public BasicPC {
  public:
    Orc(int HP, int Atk, int Def, int Gold, std::string Name, bool compass, bool BS);
};

#endif
