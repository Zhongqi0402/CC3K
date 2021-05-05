#include "cell.h"
#include "potion.h"
#include "dragon.h"
#include "goblin.h"
#include "troll.h"
#include "werewolf.h"
#include "vampire.h"
#include "phoenix.h"
#include "merchant.h"
#include "enemy.h"
#include <iostream>


Cell::Cell(size_t r, size_t c, State s) : r{ r }, c{ c }, s{ s } {}


// My neighbours will call this
// when they've changed state

void Cell::notify(Subject& whoFrom) {
 
}

State Cell::getState() const {
    return this->s;
}

void Cell::setState(const State& newState) {
    this->s = newState;
}

Info Cell::getInfo()  {
    Info i{r,c,s};
    return i;
}


Cell& Cell::operator=(const Cell& c) {
    if(&c == this) { return *this; }

    this->r = c.r;
    this->c = c.c;
    this->s = c.s;
    Cell tmp{ c };
    std::swap(this->enemy, tmp.enemy);
    std::swap(this->potion, tmp.potion);
    return *this;
}



AbstractPotion* Cell::getPotion() noexcept {
    return potion;
}

Enemy* Cell::getEnemy() {
    return enemy;
}
void Cell::setPotion(AbstractPotion* p) {
    delete potion;
    potion = p;
}
void Cell::setEnemy(Enemy* e) {
    delete enemy;
    enemy = e;
}

Cell::Cell(const Cell& c) {
    this->r = c.r;
    this->c = c.c;
    this->s = c.s;

    if (c.potion != nullptr) {

    if (c.potion->getName() == "RH") {
        this->potion = new RH{ c.potion->getHP(), c.potion->getAtk(), c.potion->getDef(), "RH" };
    }
    else if (c.potion->getName() == "BA") {
        this->potion = new BA{ c.potion->getHP(), c.potion->getAtk(), c.potion->getDef(), "BA" };
    }
    else if (c.potion->getName() == "BD") {
        this->potion = new BD{ c.potion->getHP(), c.potion->getAtk(), c.potion->getDef(), "BD" };
    }
    else if (c.potion->getName() == "PH") {
        this->potion = new PH{ c.potion->getHP(), c.potion->getAtk(), c.potion->getDef(), "PH" };
    }
    else if (c.potion->getName() == "WA") {
        this->potion = new WA{ c.potion->getHP(), c.potion->getAtk(), c.potion->getDef(), "WA" };
    }
    else {
        this->potion = new WD{ c.potion->getHP(), c.potion->getAtk(), c.potion->getDef(), "WD" };
    }
}
    if (c.enemy != nullptr) {

        if (c.enemy->getName() == "vampire") {
            this->enemy = new Vampire{ c.enemy->getHP(), c.enemy->getAtk(), c.enemy->getDef(),"vampire",
            c.enemy->getGold(), c.enemy->getMove(), c.enemy->getCompass() };
        }
        else if (c.enemy->getName() == "werewolf") {
            this->enemy = new Werewolf{ c.enemy->getHP(), c.enemy->getAtk(), c.enemy->getDef(),"werewolf",
            c.enemy->getGold(), c.enemy->getMove(), c.enemy->getCompass() };
        }
        else if (c.enemy->getName() == "goblin") {
            this->enemy = new Goblin{ c.enemy->getHP(), c.enemy->getAtk(), c.enemy->getDef(),"goblin",
            c.enemy->getGold(), c.enemy->getMove(), c.enemy->getCompass() };
        }
        else if (c.enemy->getName() == "merchant") {
            this->enemy = new Merchant{ c.enemy->getHP(), c.enemy->getAtk(), c.enemy->getDef(),"merchant",
            c.enemy->getGold(), c.enemy->getMove(), c.enemy->getCompass() };
        }
        else if (c.enemy->getName() == "dragon") {
            this->enemy = new Dragon{ c.enemy->getHP(), c.enemy->getAtk(), c.enemy->getDef(),"dragon",
            c.enemy->getGold(), c.enemy->getMove(), c.enemy->getCompass() };
        }
        else if (c.enemy->getName() == "phoenix") {
            this->enemy = new Phoenix{ c.enemy->getHP(), c.enemy->getAtk(), c.enemy->getDef(),"phoenix",
            c.enemy->getGold(), c.enemy->getMove(), c.enemy->getCompass() };
        }
        else if (c.enemy->getName() == "troll") {
            this->enemy = new Troll{ c.enemy->getHP(), c.enemy->getAtk(), c.enemy->getDef(),"troll",
            c.enemy->getGold(), c.enemy->getMove(), c.enemy->getCompass() };
        }
    }
}

Cell::~Cell() {
    delete enemy;
    enemy = nullptr;
    delete potion;
    potion = nullptr;
}
