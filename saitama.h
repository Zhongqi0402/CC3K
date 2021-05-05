#ifndef _SAITAMA_H_
#define _SAITAMA_H_

#include "basic.h"

class Saitama: public BasicPC {
  public:
    Saitama(int HP, int Atk, int Def, int Gold, std::string Name, bool compass, bool BS);
};

#endif
