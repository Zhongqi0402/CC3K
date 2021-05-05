#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "state.h"
#include "observer.h"
#include "info.h"
#include "enemy.h"

class Observer;
class Subject {
    std::vector<Observer*> ob;
    State state;
    Info info;

    public:
    virtual void setState(const State& newState);
    void attach(Observer* o);
    std::vector<Observer*> getObservers();
    virtual State getState() const;
    virtual Info getInfo() = 0;
    virtual Enemy* getEnemy() = 0;
};

#endif
