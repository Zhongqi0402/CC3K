#ifndef _DECORATOR_H_
#define _DECORATOR_H_

#include "pc.h"
#include "basic.h"
#include <string>
class AbstractPotion {	

protected:
  int HP;
  int Atk;
  int Def;
  std::string Name;

public:
  AbstractPotion(int HP, int Atk, int Def, std::string Name);
  virtual int getHP();
  virtual int getAtk();
  virtual int getDef();
  
  virtual std::string getName();
  virtual ~AbstractPotion() = 0;
};

#endif
