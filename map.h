#ifndef _MAP_H_
#define _MAP_H_

#include <cstddef>
#include <iostream>
#include <vector>
#include "cell.h"
#include "info.h"
#include "state.h"
#include "pc.h"
#include "subject.h"
class TextDisplay;
class Observer;
class InvalidMove {};

class Map {
    std::vector<std::vector<Cell>> theMap;
    size_t row, col, level;
    TextDisplay *td = nullptr;
    bool attackMerchant = false;
    bool rh = false;
    bool ba = false;
    bool bd = false;
    bool ph = false;
    bool wa = false;
    bool wd = false; 
    PC* pc = nullptr;
    State preStep = State::None;
    bool existBS = false;
    
  public:
    Map(size_t row, size_t col, size_t level, PC* pc);
    Map(std::vector<std::vector<Cell>> theMap, size_t row, size_t col, size_t level, PC* pc); // edit
    ~Map();

    void setting(); // set wall"-|" hallway"#", and the state
    void init(); // attach the empty position first, then generate enemy, potion, Gold
    std::string ifProceed(State stepState, size_t i, size_t j, size_t new_i, size_t new_j); // PC proceed if step valid
    std::string movePC(std::string direction); // PC moves to a new position, if invalid stay still
    std::string search(int r, int c); // PC search around for potions and enemies
    void moveEnemy(); // all enemies move one position each time PC moves one step
    std::string enemyAround(int r, int c); // Enemies around PC auto-attack
    std::string collectGold(State goldType); // store gold if PC step on G
    void settleGame(); // player won, settle game, print score
    std::string usePotion(std::string direction); // use the Potion in the given direction if exist
    std::string attackEnemy(std::string direction); // attack the enemy in the given direction if exist
    void resetMap(); // if enter a new floor and not floor 6, delete td, map, call setting, init
    void printStatus(std::string message);
    bool checklive(); // check if PC's HP is 0
    bool sixFloor(); // check if PC enters level 6
    friend std::ostream &operator<<(std::ostream &out, const Map &m);
};

#endif


/*
|-----------------------------------------------------------------------------|
|                                                                             |
| |--------------------------|        |-----------------------|               |
| |..........................|        |.......................|               |
| |..........................+########+.......................|-------|       |
| |..........................|   #    |...............................|--|    |
| |..........................|   #    |..................................|--| |
| |----------+---------------|   #    |----+----------------|...............| |
|            #                 #############                |...............| |
|            #                 #     |-----+------|         |...............| |
|            #                 #     |............|         |...............| |
|            ###################     |............|   ######+...............| |
|            #                 #     |............|   #     |...............| |
|            #                 #     |-----+------|   #     |--------+------| |
|  |---------+-----------|     #           #          #              #        |
|  |.....................|     #           #          #         |----+------| |
|  |.....................|     ########################         |...........| |
|  |.....................|     #           #                    |...........| |
|  |.....................|     #    |------+--------------------|...........| |
|  |.....................|     #    |.......................................| |
|  |.....................+##########+.......................................| |
|  |.....................|          |.......................................| |
|  |---------------------|          |---------------------------------------| |
|                                                                             |
|-----------------------------------------------------------------------------|
*/
