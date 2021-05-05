#include "pc.h"
#include "potion.h"

PC::PC(int HP, int Atk, int Def, int Gold, std::string Name, bool compass, bool BS) :
    HP{ HP }, Atk{ Atk }, Def{ Def }, Gold{ Gold }, Name{ Name }, Compass{ compass }, BS{ BS } {}

int PC::getHP() {
    return this->HP;
}
int PC::getAtk() {
    return this->Atk;
}
int PC::getDef() {
    return this->Def;
}
int PC::getGold() {
    return this->Gold;
}
std::string PC::getName() {
    return this->Name;
}

bool PC::getCompass() {
    return this->Compass;
}

bool PC::getBS() {
    return this->BS;
}

void PC::setHP(int HP) {
    if (HP > 0) {
        this->HP = HP;
    }
    else  {
        this->HP = 0;
    }
}

void PC::setAtk(int Atk) {
    if (Atk > 0) {
        this->Atk = Atk;
    }
    else {
        this->Atk = 0;
    }
}

void PC::setDef(int Def) {
    if (Def > 0) {
        this->Def = Def;
    }
    else {
        this->Def = 0;
    }
}

void PC::setGold(int Gold) {
    this->Gold = Gold;
}

void PC::setName(std::string Name) {
    this->Name = Name;
}

void PC::setCompass(bool compass) {
    this->Compass = compass;
}

void PC::setBS(bool BS) {
    this->BS = BS;
}

void PC::TakePotion(AbstractPotion* p) {
    AbstractPotion *potion;
    if (p->getName() == "RH") {
        potion = new RH{ 10, 0, 0, "RH" };
    } else if (p->getName() == "BA") {
        potion = new BA{ 0, 5, 0, "BA" };
    } else if (p->getName() == "BD") {
        potion = new BD{ 0, 0, 5, "BD" };
    } else if (p->getName() == "PH") {
        potion = new PH{ -10, 0, 0, "PH" };
    } else if (p->getName() == "WA") {
        potion = new WA{ 0, -5, 0, "WA" };
    } else if (p->getName() == "WD") {
        potion = new WD{ 0, 0, -5, "WD" };
    }
    ap.emplace_back(potion);
    if (Name == "Elves" && (p->getName() == "PH" || p->getName() == "WA" || p->getName() == "WD")) {
        setHP(getHP() - p->getHP());
        setAtk(getAtk() - p->getAtk());
        setDef(getDef() - p->getDef());
    } else {
        setHP(getHP() + p->getHP());
        setAtk(getAtk() + p->getAtk());
        setDef(getDef() + p->getDef());
    }
}

void PC::ReSet() {
    for (unsigned int i = 0; i < ap.size(); ++i) {
        
        if (ap[i]->getName() == "BA") {
            setAtk(getAtk() - 5);
            
        }
        if (ap[i]->getName() == "BD") {
            setDef(getDef() - 5);
            
        }
        if (ap[i]->getName() == "WA") {
           
            if (Name == "Elves") {
                setAtk(getAtk() - 5);
            } else {
                setAtk(getAtk() + 5);
            }
        }
        if (ap[i]->getName() == "WD") {
           
            if (Name == "Elves") {
                setDef(getDef() - 5);
            } else {
                setDef(getDef() + 5);
            }
        }
    }
    std::vector<AbstractPotion*> tmp;

    
    for (unsigned int i = 0; i < ap.size(); ++i) {
        

        if (ap[i]->getName() == "RH") {
            
            tmp.emplace_back(ap[i]);
        }
        if (ap[i]->getName() == "PH") {
            
            tmp.emplace_back(ap[i]);
        }
    }
    
    for(unsigned int i = 0; i < ap.size(); i += 1) {
        if(ap.at(i)->getName() == "WD" ||ap.at(i)->getName() == "BD" || ap.at(i)->getName() == "WA" || ap.at(i)->getName() == "BA") {
            delete ap.at(i);
        }
    }
    ap.clear();
    
    ap = tmp;
    
}


PC::~PC() {
    for(unsigned int i = 0; i < ap.size(); i += 1) {
        delete ap[i];
    }
    ap.clear();
}
