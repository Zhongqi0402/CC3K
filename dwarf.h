#ifndef _DWARF_H_
#define _DWARF_H_

#include "basic.h"

class Dwarf: public BasicPC {
  public:
    Dwarf(int HP, int Atk, int Def, int Gold, std::string Name, bool compass, bool BS);
};

#endif
