#ifndef _PC_H_
#define _PC_H_
#include <iostream>
#include <string>

#include <vector>

class Enemy;
class AbstractPotion;

class PC {
protected:
    int HP, Atk, Def, Gold;
    std::string Name;
    std::vector<AbstractPotion*> ap;
    bool Compass, BS;

    void setHP(int HP);
    void setAtk(int Atk);
    void setDef(int Def);
    void setName(std::string Name);

public:
    PC(int HP, int Atk, int Def, int Gold, std::string Name, bool compass, bool BS);
    int getHP();
    int getAtk();
    int getDef();
    int getGold();
    std::string getName();
    bool getCompass();
    bool getBS();
    
    void setGold(int Gold);
    void setCompass(bool compass);
    void setBS(bool BS);

    void TakePotion(AbstractPotion* p);
    void ReSet();
    virtual int Combat(Enemy* enemy) = 0;
    virtual ~PC();
};

#endif
