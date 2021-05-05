#ifndef DISPLAY_H
#define DISPLAY_H
#include "observer.h"
#include <vector>
#include <iostream>
class Subject;
class Cell;

class TextDisplay : public Observer {
    std::vector<std::vector<char>> theDisplay;
    const int r;
    const int c;

public:
    TextDisplay(int r, int c);

    void notify(Subject & whoNotified) override;

    friend std::ostream& operator<<(std::ostream& out, const TextDisplay& td);
};

#endif
