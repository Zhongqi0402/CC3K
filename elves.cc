#include "elves.h"


Elves::Elves(int HP, int Atk, int Def, int Gold, std::string Name, bool compass, bool BS) 
  : BasicPC{HP, Atk, Def, Gold, Name, compass, BS} {}
