#include "subject.h"

void Subject::setState(const State& newState) {
    this->state = newState;
}

State Subject::getState() const {
    return this->state;
}

void Subject::attach(Observer* o) {
    ob.emplace_back(o);
}

std::vector<Observer*> Subject::getObservers() {
    return ob;
}

Info Subject::getInfo() {
    return this->info;
}
