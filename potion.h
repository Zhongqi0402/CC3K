#ifndef POTION_H
#define POTION_H
#include "decorator.h"


class RH : public AbstractPotion {
    public:
	RH(int HP, int Atk, int Def,std::string Name);
};

class BA : public  AbstractPotion {
    public:
    BA(int HP, int Atk, int Def, std::string Name);
};

class BD : public AbstractPotion {
    public:
    BD(int HP, int Atk, int Def,std::string Name );
};

class PH : public AbstractPotion {
    public:
    PH(int HP, int Atk, int Def,std::string Name );
};

class WA : public AbstractPotion {
    public:
    WA(int HP, int Atk, int Def, std::string Name);
};

class WD : public AbstractPotion {
    public:
    WD(int HP, int Atk, int Def, std::string Name);
};

#endif
