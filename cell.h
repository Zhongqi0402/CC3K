#ifndef CELL_H
#define CELL_H
#include <cstddef>
#include "observer.h"
#include "state.h"
#include "subject.h"

#include "decorator.h"
#include "enemy.h"

class Cell : public Subject, public Observer {
    size_t r, c;
    State s;
    AbstractPotion* potion = nullptr;
    Enemy* enemy = nullptr;

    // Add other private members if necessary

public:
    Cell(size_t r, size_t c, State s);
    Cell& operator=(const Cell& c);
    Cell(const Cell& c);

    void notify(Subject& whoFrom) override;
    void setState(const State& newState) override;
    Info getInfo() override;

    AbstractPotion* getPotion() noexcept;
    Enemy* getEnemy() override;
    void setPotion(AbstractPotion* p);
    void setEnemy(Enemy* e);

    State getState() const override;
    ~Cell();
};
#endif
