#include "map.h"
#include "display.h"
#include "potion.h"
#include "dragon.h"
#include "goblin.h"
#include "troll.h"
#include "werewolf.h"
#include "vampire.h"
#include "phoenix.h"
#include "merchant.h"
#include "enemy.h"
#include "observer.h"
using namespace std;

std::vector<std::vector<Cell>> setMap(int row, int col) {
    std::vector<std::vector<Cell>> theMap;
    for (int i = 0; i < row; ++i) {
        std::vector<Cell> c;
        for ( int j = 0; j < col; ++j) {
            c.emplace_back(Cell(i,j,State::None));
        }
        theMap.emplace_back(c);
    }
    return theMap;
}

Map::Map(size_t row, size_t col, size_t level, PC* pc)
  : theMap{setMap(row, col)}, row{row}, col{col}, level{level}, pc{pc} {}

Map::Map(std::vector<std::vector<Cell>> theMap, size_t row, size_t col, size_t level, PC* pc)
  : theMap{theMap}, row{row}, col{col}, level{level}, pc{pc} {}



void Map::setting() { 
    td = new TextDisplay(row, col);
    // generate row 0 & 25 HWall
    for (unsigned int i = 0; i < col-1; ++i) {
        theMap[0][i].setState(State::HWall);
        td->notify(theMap[0][i]);
        theMap[row-1][i].setState(State::HWall);
        td->notify(theMap[row-1][i]);
    }
    // generate col 0 & 79 VWall
    for (unsigned int j = 0; j < row; ++j) {
        theMap[j][0].setState(State::VWall);
        td->notify(theMap[j][0]);
        theMap[j][col-1].setState(State::VWall);
        td->notify(theMap[j][col-1]);
    }
    // generate wall of top left corner chamber
    for ( int i = 3; i < 29; ++i) {
        theMap[2][i].setState(State::HWall);
        td->notify(theMap[2][i]);
        theMap[7][i].setState(State::HWall);
        td->notify(theMap[7][i]);
    }
    for (int j = 2; j < 8; ++j) {
        theMap[j][2].setState(State::VWall);
        td->notify(theMap[j][2]);
        theMap[j][29].setState(State::VWall);
        td->notify(theMap[j][29]);
    }
    // generate wall of bottom left corner chamber
    for (int i = 4; i < 25; ++i) {
        theMap[14][i].setState(State::HWall);
        td->notify(theMap[14][i]);
        theMap[22][i].setState(State::HWall);
        td->notify(theMap[22][i]);
    }
    for (int j = 14; j < 23; ++j) {
        theMap[j][3].setState(State::VWall);
        td->notify(theMap[j][3]);
        theMap[j][25].setState(State::VWall);
        td->notify(theMap[j][25]);
    }
    // generate wall of top right corner chamber
    for (int i = 39; i < 62; ++i) {
        theMap[2][i].setState(State::HWall);
        td->notify(theMap[2][i]);
        theMap[7][i].setState(State::HWall);
        td->notify(theMap[7][i]);
    }
    for (int i = 61; i < 76; ++i) {
        theMap[13][i].setState(State::HWall);
        td->notify(theMap[13][i]);
    }
    for (int i = 63; i < 70; ++i) {
        theMap[4][i].setState(State::HWall);
        td->notify(theMap[4][i]);
    }
    theMap[5][71].setState(State::HWall);
    td->notify(theMap[5][71]);
    theMap[5][72].setState(State::HWall);
    td->notify(theMap[5][72]);
    theMap[6][74].setState(State::HWall);
    td->notify(theMap[6][74]);
    theMap[6][75].setState(State::HWall);
    td->notify(theMap[6][75]);
    for (int j = 2; j < 8; ++j) {
        theMap[j][38].setState(State::VWall);
        td->notify(theMap[j][38]);
    }
    for (int j = 7; j < 14; ++j) {
        theMap[j][60].setState(State::VWall);
        td->notify(theMap[j][60]);
    }
    for (int j = 6; j < 14; ++j) {
        theMap[j][76].setState(State::VWall);
        td->notify(theMap[j][76]);
    }
    theMap[2][62].setState(State::VWall);
    td->notify(theMap[2][62]);
    theMap[3][62].setState(State::VWall);
    td->notify(theMap[3][62]);
    theMap[4][62].setState(State::VWall);
    td->notify(theMap[4][62]);
    theMap[4][70].setState(State::VWall);
    td->notify(theMap[4][70]);
    theMap[5][70].setState(State::VWall);
    td->notify(theMap[5][70]);
    theMap[5][73].setState(State::VWall);
    td->notify(theMap[5][73]);
    theMap[6][73].setState(State::VWall);
    td->notify(theMap[6][73]);
    // generate bottom right corner chamber
    for (int i = 65; i < 76; ++i) {
        theMap[15][i].setState(State::HWall);
        td->notify(theMap[15][i]);
    }
    for (int i = 37; i < 64; ++i) {
        theMap[18][i].setState(State::HWall);
        td->notify(theMap[18][i]);
    }
    for (int i = 37; i < 76; ++i) {
        theMap[22][i].setState(State::HWall);
        td->notify(theMap[22][i]);
    }
    for (int j = 18; j < 23; ++j) {
        theMap[j][36].setState(State::VWall);
        td->notify(theMap[j][36]);
    }
    for (int j = 15; j < 19; ++j) {
        theMap[j][64].setState(State::VWall);
        td->notify(theMap[j][64]);
    }
    for (int j = 15; j < 23; ++j) {
        theMap[j][76].setState(State::VWall);
        td->notify(theMap[j][76]);
    }
    // generate middle chamber
    for (int i = 38; i < 50; ++i) {
        theMap[9][i].setState(State::HWall);
        td->notify(theMap[9][i]);
        theMap[13][i].setState(State::HWall);
        td->notify(theMap[13][i]);
    }
    for (int j = 9; j < 14; ++j) {
        theMap[j][37].setState(State::VWall);
        td->notify(theMap[j][37]);
        theMap[j][50].setState(State::VWall);
        td->notify(theMap[j][50]);
    }
    // generate door
    theMap[7][13].setState(State::Door);
    td->notify(theMap[7][13]);
    theMap[4][29].setState(State::Door);
    td->notify(theMap[4][29]);
    theMap[4][38].setState(State::Door);
    td->notify(theMap[4][38]);
    theMap[7][43].setState(State::Door);
    td->notify(theMap[7][43]);
    theMap[13][69].setState(State::Door);
    td->notify(theMap[13][69]);
    theMap[11][60].setState(State::Door);
    td->notify(theMap[11][60]);
    theMap[9][43].setState(State::Door);
    td->notify(theMap[9][43]);
    theMap[13][43].setState(State::Door);
    td->notify(theMap[13][43]);
    theMap[14][13].setState(State::Door);
    td->notify(theMap[14][13]);
    theMap[20][25].setState(State::Door);
    td->notify(theMap[20][25]);
    theMap[20][36].setState(State::Door);
    td->notify(theMap[20][36]);
    theMap[18][43].setState(State::Door);
    td->notify(theMap[18][43]);
    theMap[15][69].setState(State::Door);
    td->notify(theMap[15][69]);
    // generate hallway
    for (int i = 30; i < 38; ++i) {
        theMap[4][i].setState(State::Hallway);
        td->notify(theMap[4][i]);
    }
    for (int i = 32; i < 44; ++i) {
        theMap[8][i].setState(State::Hallway);
        td->notify(theMap[8][i]);
    }
    for (int i = 14; i < 31; ++i) {
        theMap[11][i].setState(State::Hallway);
        td->notify(theMap[11][i]);
    }
    for (int i = 26; i < 36; ++i) {
        theMap[20][i].setState(State::Hallway);
        td->notify(theMap[20][i]);
    }
    for (int i = 54; i < 60; ++i) {
        theMap[11][i].setState(State::Hallway);
        td->notify(theMap[11][i]);
    }
    for (int i = 31; i < 54; ++i) {
        theMap[16][i].setState(State::Hallway);
        td->notify(theMap[16][i]);
    }
    for (int j = 5; j < 8; ++j) {
        theMap[j][33].setState(State::Hallway);
        td->notify(theMap[j][33]);
    }
    for (int j = 8; j < 14; ++j) {
        theMap[j][13].setState(State::Hallway);
        td->notify(theMap[j][13]);
    }
    for (int j = 14; j < 18; ++j) {
        theMap[j][43].setState(State::Hallway);
        td->notify(theMap[j][43]);
    }
    for (int j = 11; j < 17; ++j) {
        theMap[j][54].setState(State::Hallway);
        td->notify(theMap[j][54]);
    }
   for (int j = 8; j < 20; ++j) {
        theMap[j][31].setState(State::Hallway);
        td->notify(theMap[j][31]);
    }
    theMap[14][69].setState(State::Hallway);
    td->notify(theMap[14][69]);
    // generate empty position
    for (int i = 3; i < 7; ++i) {
        for (int j = 3; j < 29; ++j) {
            theMap[i][j].setState(State::Empty);
            td->notify(theMap[i][j]);
        }
    }
    for (int i = 15; i < 22; ++i) {
        for (int j = 4; j < 25; ++j) {
            theMap[i][j].setState(State::Empty);
            td->notify(theMap[i][j]);
        }
    }
    for (int i = 10; i < 13; ++i) {
        for (int j = 38; j < 50; ++j) {
            theMap[i][j].setState(State::Empty);
            td->notify(theMap[i][j]);
        }
    }
    for (int i = 19; i < 22; ++i) {
        for (int j = 37; j < 76; ++j) {
            theMap[i][j].setState(State::Empty);
            td->notify(theMap[i][j]);
        }
    }
    for (int i = 16; i < 19; ++i) {
        for (int j = 65; j < 76; ++j) {
            theMap[i][j].setState(State::Empty);
            td->notify(theMap[i][j]);
        }
    }
    for (int i = 3; i < 7; ++i) {
        for (int j = 39; j < 62; ++j) {
            theMap[i][j].setState(State::Empty);
            td->notify(theMap[i][j]);
        }
    }
    for (int i = 7; i < 13; ++i) {
        for (int j = 61; j < 76; ++j) {
            theMap[i][j].setState(State::Empty);
            td->notify(theMap[i][j]);
        }
    }
    for (int i = 5; i < 7; ++i) {
        for (int j = 62; j < 70; ++j) {
            theMap[i][j].setState(State::Empty);
            td->notify(theMap[i][j]);
        }
    }
    theMap[6][70].setState(State::Empty);
    td->notify(theMap[6][70]);
    theMap[6][71].setState(State::Empty);
    td->notify(theMap[6][71]);
    theMap[6][72].setState(State::Empty);
    td->notify(theMap[6][72]);
    // attach observers for empty, door
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            
            if (theMap[i][j].getInfo().thing == State::Empty || theMap[i][j].getInfo().thing == State::Door) {
                if (theMap[i-1][j-1].getInfo().thing == State::Empty || theMap[i-1][j-1].getInfo().thing == State::Door) {
                    theMap[i][j].attach(&theMap[i-1][j-1]);
                }
                if (theMap[i-1][j].getInfo().thing == State::Empty || theMap[i-1][j].getInfo().thing == State::Door) {
                    theMap[i][j].attach(&theMap[i-1][j]);
                }
                if (theMap[i-1][j+1].getInfo().thing == State::Empty || theMap[i-1][j+1].getInfo().thing == State::Door) {
                    theMap[i][j].attach(&theMap[i-1][j+1]);
                }
                if (theMap[i][j-1].getInfo().thing == State::Empty || theMap[i][j-1].getInfo().thing == State::Door) {
                    theMap[i][j].attach(&theMap[i][j-1]);
                }
                if (theMap[i][j+1].getInfo().thing == State::Empty || theMap[i][j+1].getInfo().thing == State::Door) {
                    theMap[i][j].attach(&theMap[i][j+1]);
                }
                if (theMap[i+1][j-1].getInfo().thing == State::Empty || theMap[i+1][j-1].getInfo().thing == State::Door) {
                    theMap[i][j].attach(&theMap[i+1][j-1]);
                }
                if (theMap[i+1][j].getInfo().thing == State::Empty || theMap[i+1][j].getInfo().thing == State::Door) {
                    theMap[i][j].attach(&theMap[i+1][j]);
                }
                if (theMap[i+1][j+1].getInfo().thing == State::Empty || theMap[i+1][j+1].getInfo().thing == State::Door) {
                    theMap[i][j].attach(&theMap[i+1][j+1]);
                }
            }
        }
    }
}

void Map::init() {

    srand(time(NULL));
    // genrerate vector of avaible positions

    std::vector<Cell> c;

    for (int i = 3; i < 7; ++i) {
        for (int j = 3; j < 29; ++j) {
            c.push_back(theMap[i][j]);
        }
    }
    for (int i = 15; i < 22; ++i) {
        for (int j = 4; j < 25; ++j) {
            c.push_back(theMap[i][j]);
        }
    }
    for (int i = 10; i < 13; ++i) {
        for (int j = 38; j < 50; ++j) {
            c.push_back(theMap[i][j]);
        }
    }
    for (int i = 19; i < 22; ++i) {
        for (int j = 37; j < 76; ++j) {
            c.push_back(theMap[i][j]);
        }
    }
    for (int i = 16; i < 19; ++i) {
        for (int j = 65; j < 76; ++j) {
            c.push_back(theMap[i][j]);
        }
    }
    for (int i = 3; i < 7; ++i) {
        for (int j = 39; j < 62; ++j) {
            c.push_back(theMap[i][j]);
        }
    }
    for (int i = 7; i < 13; ++i) {
        for (int j = 61; j < 76; ++j) {
            c.push_back(theMap[i][j]);
        }
    }
    for (int i = 5; i < 7; ++i) {
        for (int j = 62; j < 70; ++j) {
            c.push_back(theMap[i][j]);
        }
    }
    c.push_back(theMap[6][70]);
    c.push_back(theMap[6][71]);
    c.push_back(theMap[6][72]);

    // generating the position for PC

    int Random = rand() % c.size();
    int ro = c[Random].getInfo().row;
    int co = c[Random].getInfo().col;

    theMap[ro][co].setState(State::Character);
    td->notify(theMap[ro][co]);

    // generating the position of stairway

    while (true) {

        Random = rand() % c.size();

        ro = c[Random].getInfo().row;
        co = c[Random].getInfo().col;

        if (theMap[ro][co].getInfo().thing == State::Empty) {

            theMap[ro][co].setState(State::Stair);
            break;

        }
    }


    // generating the position of potions

    std::vector<std::vector<Cell>> m;

    std::vector<Cell> tmp;

    for (int i = 3; i < 7; ++i) {
        for (int j = 3; j < 29; ++j) {
            tmp.push_back(theMap[i][j]);
        }
    }
    m.push_back(tmp);
    tmp.clear();

    for (int i = 15; i < 22; ++i) {
        for (int j = 4; j < 25; ++j) {
            tmp.push_back(theMap[i][j]);
        }
    }
    m.push_back(tmp);
    tmp.clear();

    for (int i = 10; i < 13; ++i) {
        for (int j = 38; j < 50; ++j) {
            tmp.push_back(theMap[i][j]);
        }
    }

    m.push_back(tmp);
    tmp.clear();

    for (int i = 19; i < 22; ++i) {
        for (int j = 37; j < 76; ++j) {
            tmp.push_back(theMap[i][j]);
        }
    }
    for (int i = 16; i < 19; ++i) {
        for (int j = 65; j < 76; ++j) {
            tmp.push_back(theMap[i][j]);
        }
    }
    m.push_back(tmp);
    tmp.clear();

    for (int i = 3; i < 7; ++i) {
        for (int j = 39; j < 62; ++j) {
            tmp.push_back(theMap[i][j]);
        }
    }
    for (int i = 7; i < 13; ++i) {
        for (int j = 61; j < 76; ++j) {
            tmp.push_back(theMap[i][j]);
        }
    }
    for (int i = 5; i < 7; ++i) {
        for (int j = 62; j < 70; ++j) {
            tmp.push_back(theMap[i][j]);
        }
    }

    m.push_back(tmp);
    tmp.clear();

    for (int i = 0; i < 10; ++i) {

        int R = rand() % 5;

        while (true) {
            int r = rand() % m[R].size();
            int k = rand() % 6;

            if (m[R][r].getInfo().thing == State::Empty) {

                ro = m[R][r].getInfo().row;
                co = m[R][r].getInfo().col;

                if (k == 0) {
                    theMap[ro][co].setState(State::RH); // RH
                    theMap[ro][co].setPotion(new RH{ 10, 0, 0, "RH" });
                }

                if (k == 1) {
                    theMap[ro][co].setState(State::BA); // BA
                    theMap[ro][co].setPotion(new BA{ 0, 5, 0, "BA" });
                }

                if (k == 2) {
                    theMap[ro][co].setState(State::BD); // BD
                    theMap[ro][co].setPotion(new BD{ 0, 0, 5, "BD" });
                }

                if (k == 3) {
                    theMap[ro][co].setState(State::PH); // PH
                    theMap[ro][co].setPotion(new PH{ -10, 0, 0, "PH" });
                }

                if (k == 4) {
                    theMap[ro][co].setState(State::WA); // WA
                    theMap[ro][co].setPotion(new WA{ 0, -5, 0, "WA" });
                }

                if (k == 5) {
                    theMap[ro][co].setState(State::WD); // WD
                    theMap[ro][co].setPotion(new WD{ 0, 0, -5, "WD" });
                }
                td->notify(theMap[ro][co]);
                break;
            }
        }
    }
    vector<Cell> ev;

    // generate the gold

    for (int i = 0; i < 10; ++i) {

        int R = rand() % 5;

        while (true) {
            int r = rand() % m[R].size();
            double k = (double)rand() / RAND_MAX;

            if (m[R][r].getInfo().thing == State::Empty) {

                ro = m[R][r].getInfo().row;
                co = m[R][r].getInfo().col;

                if (k < 0.125) {
                    theMap[ro][co].setState(State::Dhorde); // dragon horde
                    while (true) {

                        int s = rand() % 8;

                        if ((s == 0) && (ro - 1 >= 0) && (co - 1 >= 0) &&
                            (theMap[ro - 1][co - 1].getInfo().thing == State::Empty)) {
                            theMap[ro - 1][co - 1].setState(State::Dragon);
                             ev.push_back(theMap[ro - 1][co - 1]);
                            theMap[ro - 1][co - 1].setEnemy(new Dragon{ 150, 20, 20, "dragon", 1, false, false });
                            td->notify(theMap[ro - 1][co - 1]);
                            break;
                        }
                        if ((s == 1) && (ro - 1 >= 0) && (co < 79) &&
                            (theMap[ro - 1][co].getInfo().thing == State::Empty)) {
                            theMap[ro - 1][co].setState(State::Dragon);
                            ev.push_back(theMap[ro - 1][co]);
                            theMap[ro - 1][co].setEnemy(new Dragon{ 150, 20, 20, "dragon", 1, false, false});
                            td->notify(theMap[ro - 1][co]);
                            
                            break;
                        }
                        if ((s == 2) && (ro - 1 >= 0) && (co + 1 < 79) &&
                            (theMap[ro - 1][co + 1].getInfo().thing == State::Empty)) {
                            theMap[ro - 1][co + 1].setState(State::Dragon);
                            td->notify(theMap[ro - 1][co + 1]);
                            ev.push_back(theMap[ro - 1][co + 1]);
                            theMap[ro - 1][co + 1].setEnemy(new Dragon{ 150, 20, 20, "dragon", 1, false, false});
                           
                            break;
                        }
                        if ((s == 3) && (ro >= 0) && (co - 1 >= 0) &&
                            (theMap[ro][co - 1].getInfo().thing == State::Empty)) {
                            theMap[ro][co - 1].setState(State::Dragon);
                            ev.push_back(theMap[ro][co - 1]);
                            theMap[ro][co - 1].setEnemy(new Dragon{ 150, 20, 20, "dragon", 1, false, false});
                            td->notify(theMap[ro][co - 1]);
                            
                            break;
                        }
                        if ((s == 4) && (ro >= 0) && (co + 1 < 79) &&
                            (theMap[ro][co + 1].getInfo().thing == State::Empty)) {
                            theMap[ro][co + 1].setState(State::Dragon);
                            ev.push_back(theMap[ro][co + 1]);
                            theMap[ro][co + 1].setEnemy(new Dragon{ 150, 20, 20, "dragon", 1, false, false});
                            td->notify(theMap[ro][co + 1]);
                            
                            break;
                        }
                        if ((s == 5) && (ro + 1 < 25) && (co - 1 >= 0) &&
                            (theMap[ro + 1][co - 1].getInfo().thing == State::Empty)) {
                            theMap[ro + 1][co - 1].setState(State::Dragon);
                            ev.push_back(theMap[ro + 1][co - 1]);
                            theMap[ro + 1][co - 1].setEnemy(new Dragon{ 150, 20, 20, "dragon", 1, false, false});
                            td->notify(theMap[ro + 1][co - 1]);
                            
                            break;
                        }
                        if ((s == 6) && (ro + 1 < 25) && (co >= 0) &&
                            (theMap[ro + 1][co].getInfo().thing == State::Empty)) {
                            theMap[ro + 1][co].setState(State::Dragon);
                            ev.push_back(theMap[ro + 1][co]);
                            theMap[ro + 1][co].setEnemy(new Dragon{ 150, 20, 20, "dragon", 1, false, false});
                            td->notify(theMap[ro + 1][co]);
                            
                            break;
                        }
                        if ((s == 7) && (ro + 1 < 25) && (co + 1 < 79) &&
                            (theMap[ro + 1][co + 1].getInfo().thing == State::Empty)) {
                            theMap[ro + 1][co + 1].setState(State::Dragon);
                            ev.push_back(theMap[ro + 1][co + 1]);
                            theMap[ro + 1][co + 1].setEnemy(new Dragon{ 150, 20, 20, "dragon", 1, false, false});
                            
                            td->notify(theMap[ro + 1][co + 1]);
                            
                            break;
                        }
                    }
                }

                else if (k < 0.375) {
                    theMap[ro][co].setState(State::Horde); // small horde
                }

                else {
                    theMap[ro][co].setState(State::Normal); // normal
                }

                td->notify(theMap[ro][co]);
                break;
            }
        }
    }

    for (int i = 0; i < 20; ++i) {

        int R = rand() % 5;

        while (true) {
            int r = rand() % m[R].size();
            double k = (double)rand() / RAND_MAX;

            if (m[R][r].getInfo().thing == State::Empty) {

                ro = m[R][r].getInfo().row;
                co = m[R][r].getInfo().col;

                if (k < ((double)(1) / (double)(9))) {
                    theMap[ro][co].setState(State::Merchant); // merchant
                    theMap[ro][co].setEnemy(new Merchant{ 30, 70, 5, "merchant", 4, false, false});
                }

                else if (k < ((double)(2) / (double)(9))) {
                    theMap[ro][co].setState(State::Phoenix); // phoenix
                    theMap[ro][co].setEnemy(new Phoenix{ 50, 35, 20, "phoenix", 1, false, false});
                }

                else if (k < ((double)(3) / (double)(9))) {
                    theMap[ro][co].setState(State::Troll); // troll
                    theMap[ro][co].setEnemy(new Troll{ 120, 25, 15, "troll", 1, false, false });
                }

                else if (k < 0.5) {
                    theMap[ro][co].setState(State::Vampire); // vampire
                    theMap[ro][co].setEnemy(new Vampire{ 50, 25, 25, "vampire", 1 , false, false});
                }

                else if (k < ((double)(13) / (double)(18))) {
                    theMap[ro][co].setState(State::Werewolf); // werewolf
                //    ev.push_back(theMap[ro][co]);
                    theMap[ro][co].setEnemy(new Werewolf{ 120, 30, 5, "werewolf", 1, false, false});
                }

                else {

                    theMap[ro][co].setState(State::Goblin); // Goblin
                    theMap[ro][co].setEnemy(new Goblin{ 70, 5, 10, "goblin", 1, false, false});
                }
                td->notify(theMap[ro][co]);
                ev.push_back(theMap[ro][co]);
                break;
            }
        }
    }

    // genreate BS

    if (!existBS) {

        int bs_r = 0;
        int bs_c = 0;

        while (true) {

            int rs = rand() % c.size();

            if (c[rs].getInfo().thing == State::Empty) {
                bs_r = c[rs].getInfo().row;
                bs_c = c[rs].getInfo().col;
                break;
            }
        }
        int random_bs = rand() % 2;

        if (random_bs == 0) {

            while (true) {

                int s = rand() % 8;

                if ((s == 0) && (bs_r - 1 >= 0) && (bs_c - 1 >= 0) &&
                    (theMap[bs_r - 1][bs_c - 1].getInfo().thing == State::Empty)) {
                    theMap[bs_r - 1][bs_c - 1].setState(State::Dragon);
                    ev.push_back(theMap[bs_r - 1][bs_c - 1]);
                    theMap[bs_r - 1][bs_c - 1].setEnemy(new Dragon{ 150, 20, 20, "dragon", 1, false, false });
                    td->notify(theMap[bs_r - 1][bs_c - 1]);
                    break;
                }
                if ((s == 1) && (bs_r - 1 >= 0) && (bs_c < 79) &&
                    (theMap[bs_r - 1][bs_c].getInfo().thing == State::Empty)) {
                    theMap[bs_r - 1][bs_c].setState(State::Dragon);
                    ev.push_back(theMap[bs_r - 1][bs_c]);
                    theMap[bs_r - 1][bs_c].setEnemy(new Dragon{ 150, 20, 20, "dragon", 1, false, false });
                    td->notify(theMap[bs_r - 1][bs_c]);
                    break;
                }
                if ((s == 2) && (bs_r - 1 >= 0) && (bs_c + 1 < 79) &&
                    (theMap[bs_r - 1][bs_c + 1].getInfo().thing == State::Empty)) {
                    theMap[bs_r - 1][bs_c + 1].setState(State::Dragon);
                    td->notify(theMap[bs_r - 1][bs_c + 1]);
                    ev.push_back(theMap[bs_r - 1][bs_c + 1]);
                    theMap[bs_r - 1][bs_c + 1].setEnemy(new Dragon{ 150, 20, 20, "dragon", 1, false, false });
                    break;
                }
                if ((s == 3) && (bs_r >= 0) && (bs_c - 1 >= 0) &&
                    (theMap[bs_r][bs_c - 1].getInfo().thing == State::Empty)) {
                    theMap[bs_r][bs_c - 1].setState(State::Dragon);
                    ev.push_back(theMap[bs_r][bs_c - 1]);
                    theMap[bs_r][bs_c - 1].setEnemy(new Dragon{ 150, 20, 20, "dragon", 1, false, false });
                    td->notify(theMap[bs_r][bs_c - 1]);
                    
                    break;
                }
                if ((s == 4) && (bs_r >= 0) && (bs_c + 1 < 79) &&
                    (theMap[bs_r][bs_c + 1].getInfo().thing == State::Empty)) {
                    theMap[bs_r][bs_c + 1].setState(State::Dragon);
                    ev.push_back(theMap[bs_r][bs_c + 1]);
                    theMap[bs_r][bs_c + 1].setEnemy(new Dragon{ 150, 20, 20, "dragon", 1, false, false });
                    td->notify(theMap[bs_r][bs_c + 1]);
                    
                    break;
                }
                if ((s == 5) && (bs_r + 1 < 25) && (bs_c - 1 >= 0) &&
                    (theMap[bs_r + 1][bs_c - 1].getInfo().thing == State::Empty)) {
                    theMap[bs_r + 1][bs_c - 1].setState(State::Dragon);
                    ev.push_back(theMap[bs_r + 1][bs_c - 1]);
                    theMap[bs_r + 1][bs_c - 1].setEnemy(new Dragon{ 150, 20, 20, "dragon", 1, false, false });
                    td->notify(theMap[bs_r + 1][bs_c - 1]);
                   
                    break;
                }
                if ((s == 6) && (bs_r + 1 < 25) && (bs_c >= 0) &&
                    (theMap[bs_r + 1][bs_c].getInfo().thing == State::Empty)) {
                    theMap[bs_r + 1][bs_c].setState(State::Dragon);
                    ev.push_back(theMap[bs_r + 1][bs_c]);
                    theMap[bs_r + 1][bs_c].setEnemy(new Dragon{ 150, 20, 20, "dragon", 1, false, false });
                    td->notify(theMap[bs_r + 1][bs_c]);
                   
                    break;
                }
                if ((s == 7) && (bs_r + 1 < 25) && (bs_c + 1 < 79) &&
                    (theMap[bs_r + 1][bs_c + 1].getInfo().thing == State::Empty)) {
                    theMap[bs_r + 1][bs_c + 1].setState(State::Dragon);
                    ev.push_back(theMap[bs_r + 1][bs_c + 1]);
                    theMap[bs_r + 1][bs_c + 1].setEnemy(new Dragon{ 150, 20, 20, "dragon", 1, false, false });

                    td->notify(theMap[bs_r + 1][bs_c + 1]);
                   
                    break;
                }
            }
            existBS = true;
            theMap[bs_r][bs_c].setState(State::BS);
            td->notify(theMap[bs_r][bs_c]);
        }
    }
    int new_random = rand() % ev.size();
    theMap[ev[new_random].getInfo().row][ev[new_random].getInfo().col].getEnemy()->setCompass(true);

}
    
std::string Map::collectGold(State goldType) { // Update PC's gold when PC steps on G
    int pcGold = pc->getGold();
    string result;
    if (goldType == State::Normal) {
            pc->setGold(pcGold+1);
            result = " and collects 1 Gold";
        
    } else if (goldType == State::Horde) {
            pc->setGold(pcGold+2);
            result = " and collects 2 Gold";
        
    } else if (goldType == State::Mhorde) {
            pc->setGold(pcGold+4);
            result = " and collects 4 Gold";
        
    } else if (goldType == State::Dhorde) {
        
            pc->setGold(pcGold+6);
            result = " and collects 6 Gold";
        
    }
    return result;
}

void Map::settleGame() { // player won, display score
    int pcGold = pc->getGold();
    int score = 0;
    if (pc->getName() == "Human") {
        score = 1.5 * pcGold;
        if (pcGold % 2 == 0) {
        std::cout << "Score: " << score << std::endl;
        } else if (pcGold % 2 == 1) {
        std::cout << "Score: " << score << ".5" << std::endl;
        }
    } else if(pc->getName() == "Orc") {
        score = pcGold / 2;
        if (pcGold % 2 == 0) {
        std::cout << "Score: " << score << std::endl;
        } else if (pcGold % 2 == 1) {
        std::cout << "Score: " << score << ".5" << std::endl;
        }
    } else if(pc->getName() == "Dwarf") {
        score = 2 * pcGold;
        std::cout << "Score: " << score << std::endl;
    } else if(pc->getName() == "Elves" || pc->getName() == "Saitama") {
        std::cout << "Score: " << pc->getGold() << std::endl;
    }
    std::cout << "Congratulations!" << std::endl;
    
    std::cout << "GAME END" << std::endl;
    return;
}

std::string Map::ifProceed(State stepState, size_t i, size_t j, size_t new_i, size_t new_j) {
    string result;

    if (stepState == State::Empty || stepState == State::Normal || stepState == State::Horde ||
        stepState == State::Mhorde || stepState == State::Dhorde || stepState == State::Compass ||
        stepState == State::Door || stepState == State::Hallway || stepState == State::BS ||
        (stepState == State::Stair && pc->getCompass() == false)) {
        if (stepState == State::Normal || stepState == State::Horde ||
            stepState == State::Mhorde) {
            result = collectGold(stepState);
        }
        if (stepState == State::Dhorde || stepState == State::BS) {
            if (theMap[new_i-1][new_j].getState() == State::Dragon ||
                theMap[new_i-1][new_j+1].getState() == State::Dragon ||
                theMap[new_i][new_j+1].getState() == State::Dragon ||
                theMap[new_i+1][new_j+1].getState() == State::Dragon ||
                theMap[new_i+1][new_j].getState() == State::Dragon ||
                theMap[new_i+1][new_j-1].getState() == State::Dragon ||
                theMap[new_i][new_j-1].getState() == State::Dragon ||
                theMap[new_i-1][new_j-1].getState() == State::Dragon) {
                return result;
            } else {
                if(stepState == State::Dhorde) result = collectGold(stepState);
                if(stepState == State::BS) {
                    pc->setBS(true);
                    result = " and found Barrier Suit";
                }
            }
        }
        if (stepState == State::Compass) {
            pc->setCompass(true);
	        for (size_t i = 0; i < row; ++i) {
		        for (size_t j = 0; j < col; ++j) {
		            if (theMap[i][j].getState() == State::Stair) {
			            td->notify(theMap[i][j]);
                        result = " and found compass";
		            }
		        }
	        }
        }
        if (stepState == State::Stair) {
            Map::level += 1;
            if (Map::level == 6) {
                settleGame();
                return result;
            } else if (Map::level != 6) {
                preStep = State::None;
                result += " and found hidden stair. PC enters floor " + std::to_string(Map::level);
                Map::resetMap();
                return result;
            }
        }
        theMap[i][j].setState(State::Empty);
        if (preStep == State::Door) {
            theMap[i][j].setState(State::Door);
        } else if (preStep == State::Hallway) {
            theMap[i][j].setState(State::Hallway);
        }
        td->notify(theMap[i][j]);
        preStep = stepState;
        theMap[new_i][new_j].setState(State::Character);
        td->notify(theMap[new_i][new_j]);
    } else if (stepState == State::Stair && pc->getCompass() == true) {
        pc->setCompass(false);
	    Map::level += 1;
        if (Map::level == 6) {
            settleGame();
            return result;
        } else if (Map::level != 6) {
            preStep = State::None;
            result += " and enters floor " + std::to_string(Map::level);
            Map::resetMap();
            return result;
        }
    } else {
        return " invalid";
    }
    result += Map::search(new_i, new_j);
    return result;
}


std::string Map::movePC(std::string direction) {
    // PC move to an empty postion, or pick up gold or compass,
    // if PC steps to the stair and holds the compass, PC moves to next floor
    std::string report = "PC moves ";
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            if (theMap[i][j].getInfo().thing == State::Character) { // find position of character
                
                if (direction == "no") {
                    report += "North";
                    State stepState = theMap[i-1][j].getInfo().thing;
                    report += ifProceed(stepState, i, j, i-1, j);
                    if(report == "PC moves North invalid") return "Direction blocked. Please reenter.";
                    moveEnemy();
                    report += enemyAround(i-1, j);
                    
                } else if (direction == "ne") {
                    report += "North East";
                    State stepState = theMap[i-1][j+1].getInfo().thing;
                    report += ifProceed(stepState, i, j, i-1, j+1);
                    if(report == "PC moves North East invalid") return "Direction blocked. Please reenter.";
                    moveEnemy();
                    report += enemyAround(i-1, j+1);
                    
                } else if (direction == "ea") {
                    report += "East";
                    State stepState = theMap[i][j+1].getInfo().thing;
                    report += ifProceed(stepState, i, j, i, j+1);
                    if(report == "PC moves East invalid") return "Direction blocked. Please reenter.";
                    moveEnemy();
                    report += enemyAround(i, j+1);
                    
                } else if (direction == "se") {
                    report += "South East";
                    State stepState = theMap[i+1][j+1].getInfo().thing;
                    report += ifProceed(stepState, i, j, i+1, j+1);
                    if(report == "PC moves South East invalid") return "Direction blocked. Please reenter.";
                    moveEnemy();
                    report += enemyAround(i+1, j+1);
                    
                } else if (direction == "so") {
                    report += "South";
                    State stepState = theMap[i+1][j].getInfo().thing;
                    report += ifProceed(stepState, i, j, i+1, j);
                    if(report == "PC moves South invalid") return "Direction blocked. Please reenter.";
                    moveEnemy();
                    report += enemyAround(i+1, j);
                    
                } else if (direction == "sw") {
                    report += "South West";
                    State stepState = theMap[i+1][j-1].getInfo().thing;
                    report += ifProceed(stepState, i, j, i+1, j-1);
                    if(report == "PC moves South West invalid") return "Direction blocked. Please reenter.";
                    moveEnemy();
                    report += enemyAround(i+1, j-1);
                    
                } else if (direction == "we") {
                    report += "West";
                    State stepState = theMap[i][j-1].getInfo().thing;
                    report += ifProceed(stepState, i, j, i, j-1);
                    if(report == "PC moves West invalid") return "Direction blocked. Please reenter.";
                    moveEnemy();
                    report += enemyAround(i, j-1);
                    
                } else if (direction == "nw") {
                    report += "North West";
                    State stepState = theMap[i-1][j-1].getInfo().thing;
                    report += ifProceed(stepState, i, j, i-1, j-1);
                    if(report == "PC moves North West invalid") return "Direction blocked. Please reenter.";
                    moveEnemy();
                    report += enemyAround(i-1, j-1);
                }
                if (pc->getHP() <= 0) {
                    int pcGold = pc->getGold();
                    int score = 0;
                    if (pc->getName() == "Human") {
                        score = 1.5 * pcGold;
                        if (pcGold % 2 == 0) {
                        report += "Score: " + std::to_string(score) + "\n";
                        } else if (pcGold % 2 == 1) {
                        report += "Score: " + std::to_string(score) + ".5\n";
                        }
                    } else if(pc->getName() == "Orc") {
                        score = pcGold / 2;
                        if (pcGold % 2 == 0) {
                        report += "Score: " + std::to_string(score) + "\n";
                        } else if (pcGold % 2 == 1) {
                        report += "Score: " + std::to_string(score) + ".5\n";
                        }
                    } else if(pc->getName() == "Dwarf") {
                        score = 2 * pcGold;
                        report += "Score: " + std::to_string(score) + "\n";
                    } else if(pc->getName() == "Elves" || pc->getName() == "Saitama") {
                        report += "Score: " + std::to_string(pc->getGold()) + "\n";
                    }
                    report += "You lose.\n";
                    
                    report += "GAME END\n";
                }
                return report;
            }
        }
        
    }
    return "Direction blocked. Please reenter."; 
}

std::string Map::search(int r, int c) {
    std::string report = " and sees ";
    std::vector<Cell> neighbours;
    if (theMap[r-1][c].getState() == State::RH || theMap[r-1][c].getState() == State::BA ||
        theMap[r-1][c].getState() == State::BD || theMap[r-1][c].getState() == State::PH ||
        theMap[r-1][c].getState() == State::WA || theMap[r-1][c].getState() == State::WD)
        neighbours.emplace_back(theMap[r-1][c]); // no
    if (theMap[r-1][c+1].getState() == State::RH || theMap[r-1][c+1].getState() == State::BA ||
        theMap[r-1][c+1].getState() == State::BD || theMap[r-1][c+1].getState() == State::PH ||
        theMap[r-1][c+1].getState() == State::WA || theMap[r-1][c+1].getState() == State::WD)
        neighbours.emplace_back(theMap[r-1][c+1]); // ne
    if (theMap[r][c+1].getState() == State::RH || theMap[r][c+1].getState() == State::BA ||
        theMap[r][c+1].getState() == State::BD || theMap[r][c+1].getState() == State::PH ||
        theMap[r][c+1].getState() == State::WA || theMap[r][c+1].getState() == State::WD)
        neighbours.emplace_back(theMap[r][c+1]); //ea
    if (theMap[r-1][c].getState() == State::RH || theMap[r+1][c+1].getState() == State::BA ||
        theMap[r+1][c+1].getState() == State::BD || theMap[r+1][c+1].getState() == State::PH ||
        theMap[r+1][c+1].getState() == State::WA || theMap[r+1][c+1].getState() == State::WD)
        neighbours.emplace_back(theMap[r+1][c+1]); //se
    if (theMap[r+1][c].getState() == State::RH || theMap[r+1][c].getState() == State::BA ||
        theMap[r+1][c].getState() == State::BD || theMap[r+1][c].getState() == State::PH ||
        theMap[r+1][c].getState() == State::WA || theMap[r+1][c].getState() == State::WD)
        neighbours.emplace_back(theMap[r+1][c]); //so
    if (theMap[r+1][c-1].getState() == State::RH || theMap[r+1][c-1].getState() == State::BA ||
        theMap[r+1][c-1].getState() == State::BD || theMap[r+1][c-1].getState() == State::PH ||
        theMap[r+1][c-1].getState() == State::WA || theMap[r+1][c-1].getState() == State::WD) 
        neighbours.emplace_back(theMap[r+1][c-1]); // sw
    if (theMap[r][c-1].getState() == State::RH || theMap[r][c-1].getState() == State::BA ||
        theMap[r][c-1].getState() == State::BD || theMap[r][c-1].getState() == State::PH ||
        theMap[r][c-1].getState() == State::WA || theMap[r][c-1].getState() == State::WD)
        neighbours.emplace_back(theMap[r][c-1]); //we
    if (theMap[r-1][c-1].getState() == State::RH || theMap[r-1][c-1].getState() == State::BA ||
        theMap[r-1][c-1].getState() == State::BD || theMap[r-1][c-1].getState() == State::PH ||
        theMap[r-1][c-1].getState() == State::WA || theMap[r-1][c-1].getState() == State::WD)
        neighbours.emplace_back(theMap[r-1][c-1]);//nw
    
    for (unsigned int i = 0; i < neighbours.size(); ++i) {
        State found = neighbours[i].getState();
        if (found == State::RH) {
            if (this->rh == false) {
                report += "an unknown potion. ";
            } else if (this->rh == true) {
                report += "an RH. ";
            }
        } else if (found == State::BA) {
            if (this->ba == false) {
                report += "an unknown potion. ";
            } else if (this->ba == true) {
                report += "a BA. ";
            }
        } else if (found == State::BD) {
            if (this->bd == false) {
                report += "an unknown potion. ";
            } else if (this->bd == true) {
                report += "a BD. ";
            }
        } else if (found == State::PH) {
            if (this->ph == false) {
                report += "an unknown potion. ";
            } else if (this->ph == true) {
                report += "a PH. ";
            }
        } else if (found == State::WA) {
            if (this->wa == false) {
                report += "an unknown potion. ";
            } else if (this->wa == true) {
                report += "a WA. ";
            }
        } else if (found == State::WD) {
            if (this->wd == false) {
                report += "an unknown potion. ";
            } else if (this->wd == true) {
                report += "a WD. ";
            }
        } 
    }
    if (report != " and sees ") {
        return report;
    } else return ".";
}

void Map::moveEnemy() {
    srand(time(NULL));
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            State enemy = theMap[i][j].getInfo().thing;
            if ((enemy == State::Vampire || enemy == State::Werewolf || enemy == State::Goblin ||
                enemy == State::Troll || enemy == State::Merchant || enemy == State::Phoenix) &&
                theMap[i][j].getEnemy()->getMove() == false) {
                std::vector<Cell> select;
                if (theMap[i-1][j].getInfo().thing == State::Empty) select.emplace_back(theMap[i-1][j]); // no
                if (theMap[i-1][j+1].getInfo().thing == State::Empty) select.emplace_back(theMap[i-1][j+1]); // ne
                if (theMap[i][j+1].getInfo().thing == State::Empty) select.emplace_back(theMap[i][j+1]); //ea
                if (theMap[i+1][j+1].getInfo().thing == State::Empty) select.emplace_back(theMap[i+1][j+1]); //se
                if (theMap[i+1][j].getInfo().thing == State::Empty) select.emplace_back(theMap[i+1][j]); //so
                if (theMap[i+1][j-1].getInfo().thing == State::Empty) select.emplace_back(theMap[i+1][j-1]); // sw
                if (theMap[i][j-1].getInfo().thing == State::Empty) select.emplace_back(theMap[i][j-1]); //we
                if (theMap[i-1][j-1].getInfo().thing == State::Empty) select.emplace_back(theMap[i-1][j-1]); //nw
                int random = rand() % select.size();
                int new_row = select[random].getInfo().row;
                int new_col = select[random].getInfo().col;
                theMap[new_row][new_col].setState(enemy);
                td->notify(theMap[new_row][new_col]);
                int HP = theMap[i][j].getEnemy()->getHP();
                if (enemy == State::Vampire) theMap[new_row][new_col].setEnemy(new Vampire{ HP, 25, 25, "vampire", 1, true, theMap[i][j].getEnemy()->getCompass()});
                if (enemy == State::Werewolf) theMap[new_row][new_col].setEnemy(new Werewolf{ HP, 30, 5, "werewolf", 1, true, theMap[i][j].getEnemy()->getCompass() });
                if (enemy == State::Goblin) theMap[new_row][new_col].setEnemy(new Goblin{ HP, 5, 10, "goblin", 1, true, theMap[i][j].getEnemy()->getCompass() });
                if (enemy == State::Troll) theMap[new_row][new_col].setEnemy(new Troll{ HP, 25, 15, "troll", 1, true, theMap[i][j].getEnemy()->getCompass() });
                if (enemy == State::Merchant) theMap[new_row][new_col].setEnemy(new Merchant{ HP, 70, 5, "merchant", 4, true, theMap[i][j].getEnemy()->getCompass() });
                if (enemy == State::Phoenix) theMap[new_row][new_col].setEnemy(new Phoenix{ HP, 35, 20, "phoenix", 1, true, theMap[i][j].getEnemy()->getCompass() });
                theMap[i][j].setState(State::Empty);
                td->notify(theMap[i][j]);
            }
        }
    }
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            State enemy = theMap[i][j].getInfo().thing;
            if (enemy == State::Vampire || enemy == State::Werewolf || enemy == State::Goblin ||
                enemy == State::Troll || enemy == State::Merchant || enemy == State::Phoenix) {
                theMap[i][j].getEnemy()->setMove(false);
            }
        }
    }
}

std::string Map::enemyAround(int r, int c) {
    int damage;
    std::string report;
    std::vector<Cell> neighbours;
    
    if (theMap[r-1][c].getEnemy() != nullptr) neighbours.emplace_back(theMap[r-1][c]); // no
    if (theMap[r-1][c+1].getEnemy() != nullptr) neighbours.emplace_back(theMap[r-1][c+1]); // ne
    if (theMap[r][c+1].getEnemy() != nullptr) neighbours.emplace_back(theMap[r][c+1]); //ea
    if (theMap[r+1][c+1].getEnemy() != nullptr) neighbours.emplace_back(theMap[r+1][c+1]); //se
    if (theMap[r+1][c].getEnemy() != nullptr) neighbours.emplace_back(theMap[r+1][c]); //so
    if (theMap[r+1][c-1].getEnemy() != nullptr) neighbours.emplace_back(theMap[r+1][c-1]); // sw
    if (theMap[r][c-1].getEnemy() != nullptr) neighbours.emplace_back(theMap[r][c-1]); //we
    if (theMap[r-1][c-1].getEnemy() != nullptr) neighbours.emplace_back(theMap[r-1][c-1]); //nw
    
    for (unsigned int i = 0; i < neighbours.size(); ++i) {
        State found = neighbours[i].getState();
        int ro = neighbours[i].getInfo().row;
        int co = neighbours[i].getInfo().col;
        if (found == State::Vampire) {
           
            damage = pc->Combat(theMap[ro][co].getEnemy());
            
            report += (" A Vampire deals " + std::to_string(damage) + " to PC. ");
        } else if (found == State::Goblin) {
            
            damage = pc->Combat(theMap[ro][co].getEnemy());
            
            report += (" A Goblin deals " + std::to_string(damage) + " to PC. ");
        } else if (found == State::Werewolf) {
            
            damage = pc->Combat(theMap[ro][co].getEnemy());
            
            report += (" A Werewolf deals " + std::to_string(damage) + " to PC. ");
        } else if (found == State::Troll) {
            
            damage = pc->Combat(theMap[ro][co].getEnemy());
            
            report += (" A Troll deals " + std::to_string(damage) + " to PC. ");
        } else if (found == State::Merchant) {
            if (attackMerchant == true) {
                damage = pc->Combat(theMap[ro][co].getEnemy());
                report += (" A Merchant deals " + std::to_string(damage) + " to PC. ");
            } else if (attackMerchant == false) {
                report += " PC sees a Merchant. ";
            }
        } else if (found == State::Dragon) {
            report += " PC sees a Dragon. ";
        } else if (found == State::Phoenix) {
            damage = pc->Combat(theMap[ro][co].getEnemy());
            report += (" A Phoenix deals " + std::to_string(damage) + " to PC. ");
        }
    }
    return report;
}

std::string Map::usePotion(std::string direction) {
    std::string error = "It is not a valid direction command.";
    size_t i;
    size_t j;
    for (size_t pc_row = 0; pc_row < row; ++pc_row) {
        for (size_t pc_col = 0; pc_col < col; ++pc_col) {
            if (theMap[pc_row][pc_col].getInfo().thing == State::Character) {
                i = pc_row;
                j = pc_col;
            }
        }
    }
    std::string result;
    std::string dir;
    Cell now = theMap.at(i).at(j);
    int resultC = 0;
    int resultR = 0;
    if(direction == "no") {
       
        now = theMap.at(i-1).at(j);
        resultC = j;
        resultR = i-1;
        dir = "North";
        
    }
    else if(direction == "so") {
        
        now = theMap.at(i+1).at(j);
        resultC = j;
        resultR = i+1;
        dir = "South";
    }
    else if(direction == "ea") {
        
        now = theMap.at(i).at(j+1);
        resultC = j+1;
        resultR = i;
        dir = "East";
    }
    else if(direction == "we") {
        
        now = theMap.at(i).at(j-1);
        resultC = j-1;
        resultR = i;
        dir = "West";
    }
    else if(direction == "ne") {

        now = theMap.at(i-1).at(j+1);
        resultC = j+1;
        resultR = i-1;
        dir = "Northeast";
    }
    else if(direction == "nw") {
        
        now = theMap.at(i-1).at(j-1);
        resultC = j-1;
        resultR = i-1;
        dir = "Northwest";
    }
    else if(direction == "se") {
        
        now = theMap.at(i+1).at(j+1);
        resultC = j+1;
        resultR = i+1;
        dir = "Southeast";
    }
    else if(direction == "sw") {
        
        now = theMap.at(i+1).at(j-1);
        resultC = j-1;
        resultR = i+1;
        dir = "Southwest";
    } else {
        return error;
    }
    
    if (now.getState() == State::RH || now.getState() == State::BA ||
        now.getState() == State::BD || now.getState() == State::PH ||
        now.getState() == State::WA || now.getState() == State::WD ) {
            
            pc->TakePotion(now.getPotion());
            theMap[resultR][resultC].setState(State::Empty);
            td->notify(theMap[resultR][resultC]);

            if(now.getState() == State::RH) rh = true;
            if(now.getState() == State::BA) ba = true;
            if(now.getState() == State::BD) bd = true;
            if(now.getState() == State::PH) ph= true;
            if(now.getState() == State::WA) wa = true;
            if(now.getState() == State::WD) wd = true;
            result = "Player used " +  now.getPotion()->getName() + " in the " + dir;
            moveEnemy();
            result += enemyAround(i, j);
            if (pc->getHP() <= 0) {
                int pcGold = pc->getGold();
                int score = 0;
                if (pc->getName() == "Human") {
                    score = 1.5 * pcGold;
                    if (pcGold % 2 == 0) {
                    result += "Score: " + std::to_string(score) + "\n";
                    } else if (pcGold % 2 == 1) {
                    result += "Score: " + std::to_string(score) + ".5\n";
                    }
                } else if(pc->getName() == "Orc") {
                    score = pcGold / 2;
                    if (pcGold % 2 == 0) {
                    result += "Score: " + std::to_string(score) + "\n";
                    } else if (pcGold % 2 == 1) {
                    result += "Score: " + std::to_string(score) + ".5\n";
                    }
                } else if(pc->getName() == "Dwarf") {
                    score = 2 * pcGold;
                    result += "Score: " + std::to_string(score) + "\n";
                } else if(pc->getName() == "Elves" || pc->getName() == "Saitama") {
                    result += "Score: " + std::to_string(pc->getGold()) + "\n";
                }
                result += "You lose.\n";
                
                result += "GAME END\n";
            }
            return result;
    } else {
        result = "It is not a potion in the direction you entered.";
        return result;
    }
}
    
std::string Map::attackEnemy(std::string direction) {

    int r = 0;
    int c = 0;
    std::string result;

    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            if (theMap[i][j].getInfo().thing == State::Character) {
                r = i;
                c = j;
            }
        }
    }

    if ((direction == "no") && ((theMap[r - 1][c].getInfo().thing == State::Vampire)
        || (theMap[r - 1][c].getInfo().thing == State::Werewolf) ||
        (theMap[r - 1][c].getInfo().thing == State::Goblin) ||
        (theMap[r - 1][c].getInfo().thing == State::Merchant) ||
        (theMap[r - 1][c].getInfo().thing == State::Dragon) ||
        (theMap[r - 1][c].getInfo().thing == State::Phoenix) ||
        (theMap[r - 1][c].getInfo().thing == State::Troll))) {
       
        if (theMap[r - 1][c].getInfo().thing == State::Merchant) attackMerchant = true;
        int i = theMap[r - 1][c].getEnemy()->Combat(pc);
        std::string str;
        int live = theMap[r - 1][c].getEnemy()->getHP();

        if (theMap[r - 1][c].getInfo().thing == State::Werewolf) str = "W";
        if (theMap[r - 1][c].getInfo().thing == State::Goblin) str = "N";
        if (theMap[r - 1][c].getInfo().thing == State::Merchant) str = "M";
        if (theMap[r - 1][c].getInfo().thing == State::Dragon) str = "D";
        if (theMap[r - 1][c].getInfo().thing == State::Phoenix) str = "X";
        if (theMap[r - 1][c].getInfo().thing == State::Troll) str = "T";
        if (theMap[r - 1][c].getInfo().thing == State::Vampire) str = "V";

        result = "PC deals " + std::to_string(i) + " damge to " + str + " (" + std::to_string(live)
            + " HP).";

        if (theMap[r - 1][c].getEnemy()->getHP() > 0) {
            int j = pc->Combat(theMap[r - 1][c].getEnemy());
            result = result + " " + str + " deals " + std::to_string(j) + " damage to PC.";
        }
        else {
            pc->setGold(pc->getGold() + theMap[r - 1][c].getEnemy()->getGold());
            theMap[r - 1][c].setState(State::Empty);
            td->notify(theMap[r - 1][c]);
            int k = theMap[r - 1][c].getEnemy()->getGold();
            result = result + " PC get " + std::to_string(k) + " gold.";
            if (theMap[r - 1][c].getEnemy()->getCompass() == true) {
                theMap[r - 1][c].setState(State::Compass);
                td->notify(theMap[r - 1][c]);
            }
        }
    }
    else if ((direction == "so") && ((theMap[r + 1][c].getInfo().thing == State::Vampire)
        || (theMap[r + 1][c].getInfo().thing == State::Werewolf) ||
        (theMap[r + 1][c].getInfo().thing == State::Goblin) ||
        (theMap[r + 1][c].getInfo().thing == State::Merchant) ||
        (theMap[r + 1][c].getInfo().thing == State::Dragon) ||
        (theMap[r + 1][c].getInfo().thing == State::Phoenix) ||
        (theMap[r + 1][c].getInfo().thing == State::Troll))) {
        
        int i = theMap[r + 1][c].getEnemy()->Combat(pc);
        cout << i << endl;
        if (theMap[r + 1][c].getInfo().thing == State::Merchant) attackMerchant = true;
        
        std::string str;
        int live = theMap[r + 1][c].getEnemy()->getHP();
        if (theMap[r + 1][c].getInfo().thing == State::Werewolf) str = "W";
        if (theMap[r + 1][c].getInfo().thing == State::Goblin) str = "N";
        if (theMap[r + 1][c].getInfo().thing == State::Merchant) str = "M";
        if (theMap[r + 1][c].getInfo().thing == State::Dragon) str = "D";
        if (theMap[r + 1][c].getInfo().thing == State::Phoenix) str = "X";
        if (theMap[r + 1][c].getInfo().thing == State::Troll) str = "T";
        if (theMap[r + 1][c].getInfo().thing == State::Vampire) str = "V";

        result = "PC deals " + std::to_string(i) + " damge to " + str + " (" + std::to_string(live)
            + " HP).";
        if (theMap[r + 1][c].getEnemy()->getHP() > 0) {
            int j = pc->Combat(theMap[r + 1][c].getEnemy());
            result = result + " " + str + " deals " + std::to_string(j) + " damage to PC.";
        }
        else {
            pc->setGold(pc->getGold() + theMap[r + 1][c].getEnemy()->getGold());
            theMap[r + 1][c].setState(State::Empty);
            td->notify(theMap[r + 1][c]);
            int k = theMap[r + 1][c].getEnemy()->getGold();
            result = result + " PC get " + std::to_string(k) + " gold.";
            if (theMap[r + 1][c].getEnemy()->getCompass() == true) {
                theMap[r + 1][c].setState(State::Compass);
                td->notify(theMap[r + 1][c]);
            }
        }
    }
    else if ((direction == "we") && ((theMap[r][c - 1].getInfo().thing == State::Vampire)
        || (theMap[r][c - 1].getInfo().thing == State::Werewolf) ||
        (theMap[r][c - 1].getInfo().thing == State::Goblin) ||
        (theMap[r][c - 1].getInfo().thing == State::Merchant) ||
        (theMap[r][c - 1].getInfo().thing == State::Dragon) ||
        (theMap[r][c - 1].getInfo().thing == State::Phoenix) ||
        (theMap[r][c - 1].getInfo().thing == State::Troll))) {
        
        if (theMap[r][c - 1].getInfo().thing == State::Merchant) attackMerchant = true;
        int i = theMap[r][c - 1].getEnemy()->Combat(pc);
       
        
        std::string str;
        int live = theMap[r][c - 1].getEnemy()->getHP();
        if (theMap[r][c - 1].getInfo().thing == State::Werewolf) str = "W";
        if (theMap[r][c - 1].getInfo().thing == State::Goblin) str = "N";
        if (theMap[r][c - 1].getInfo().thing == State::Merchant) str = "M";
        if (theMap[r][c - 1].getInfo().thing == State::Dragon) str = "D";
        if (theMap[r][c - 1].getInfo().thing == State::Phoenix) str = "X";
        if (theMap[r][c - 1].getInfo().thing == State::Troll) str = "T";
        if (theMap[r][c - 1].getInfo().thing == State::Vampire) str = "V";

        result = "PC deals " + std::to_string(i) + " damge to " + str + " (" + std::to_string(live)
            + " HP).";

        if (theMap[r][c - 1].getEnemy()->getHP() > 0) {
            int j = pc->Combat(theMap[r][c - 1].getEnemy());
            result = result + " " + str + " deals " + std::to_string(j) + " damage to PC.";

        }
        else {
            pc->setGold(pc->getGold() + theMap[r ][c - 1].getEnemy()->getGold());
            theMap[r][c - 1].setState(State::Empty);
            td->notify(theMap[r][c - 1]);
            int k = theMap[r][c - 1].getEnemy()->getGold();
            result = result + " PC get " + std::to_string(k) + " gold.";
            if (theMap[r][c - 1].getEnemy()->getCompass() == true) {
                theMap[r][c - 1].setState(State::Compass);
                td->notify(theMap[r][c - 1]);
            }
        }
    }
    else if ((direction == "ea") && ((theMap[r][c + 1].getInfo().thing == State::Vampire)
        || (theMap[r][c + 1].getInfo().thing == State::Werewolf) ||
        (theMap[r][c + 1].getInfo().thing == State::Goblin) ||
        (theMap[r][c + 1].getInfo().thing == State::Merchant) ||
        (theMap[r][c + 1].getInfo().thing == State::Dragon) ||
        (theMap[r][c + 1].getInfo().thing == State::Phoenix) ||
        (theMap[r][c + 1].getInfo().thing == State::Troll))) {
        
        int i = theMap[r][c + 1].getEnemy()->Combat(pc);
       
        if (theMap[r][c + 1].getInfo().thing == State::Merchant) attackMerchant = true;
        std::string str;
        int live = theMap[r][c + 1].getEnemy()->getHP();
        if (theMap[r][c + 1].getInfo().thing == State::Werewolf) str = "W";
        if (theMap[r][c + 1].getInfo().thing == State::Goblin) str = "N";
        if (theMap[r][c + 1].getInfo().thing == State::Merchant) str = "M";
        if (theMap[r][c + 1].getInfo().thing == State::Dragon) str = "D";
        if (theMap[r][c + 1].getInfo().thing == State::Phoenix) str = "X";
        if (theMap[r][c + 1].getInfo().thing == State::Troll) str = "T";
        if (theMap[r][c + 1].getInfo().thing == State::Vampire) str = "V";

        result = "PC deals " + std::to_string(i) + " damge to " + str + " (" + std::to_string(live)
            + " HP).";

        if (theMap[r][c + 1].getEnemy()->getHP() > 0) {
            int j = pc->Combat(theMap[r][c + 1].getEnemy());
            result = result + " " + str + " deals " + std::to_string(j) + " damage to PC.";

        }
        else {
            pc->setGold(pc->getGold() + theMap[r][c + 1].getEnemy()->getGold());
            theMap[r][c + 1].setState(State::Empty);
            td->notify(theMap[r][c + 1]);
            int k = theMap[r][c + 1].getEnemy()->getGold();
            result = result + " PC get " + std::to_string(k) + " gold.";
            if (theMap[r][c + 1].getEnemy()->getCompass() == true) {
                theMap[r][c + 1].setState(State::Compass);
                td->notify(theMap[r][c + 1]);
            }
        }
    }
    else if ((direction == "ne") && ((theMap[r - 1][c + 1].getInfo().thing == State::Vampire)
        || (theMap[r - 1][c + 1].getInfo().thing == State::Werewolf) ||
        (theMap[r - 1][c + 1].getInfo().thing == State::Goblin) ||
        (theMap[r - 1][c + 1].getInfo().thing == State::Merchant) ||
        (theMap[r - 1][c + 1].getInfo().thing == State::Dragon) ||
        (theMap[r - 1][c + 1].getInfo().thing == State::Phoenix) ||
        (theMap[r - 1][c + 1].getInfo().thing == State::Troll))) {
      
        int i = theMap[r - 1][c + 1].getEnemy()->Combat(pc);
       
        if (theMap[r - 1][c + 1].getInfo().thing == State::Merchant) attackMerchant = true;
        std::string str;
        int live = theMap[r - 1][c + 1].getEnemy()->getHP();
        if (theMap[r - 1][c + 1].getInfo().thing == State::Werewolf) str = "W";
        if (theMap[r - 1][c + 1].getInfo().thing == State::Goblin) str = "N";
        if (theMap[r - 1][c + 1].getInfo().thing == State::Merchant) str = "M";
        if (theMap[r - 1][c + 1].getInfo().thing == State::Dragon) str = "D";
        if (theMap[r - 1][c + 1].getInfo().thing == State::Phoenix) str = "X";
        if (theMap[r - 1][c + 1].getInfo().thing == State::Troll) str = "T";
        if (theMap[r - 1][c + 1].getInfo().thing == State::Vampire) str = "V";
        result = "PC deals " + std::to_string(i) + " damge to " + str + " (" + std::to_string(live)
            + " HP).";

        if (theMap[r - 1][c + 1].getEnemy()->getHP() > 0) {

            int j = pc->Combat(theMap[r - 1][c + 1].getEnemy());
            result = result + " " + str + " deals " + std::to_string(j) + " damage to PC.";

        }
        else {
            pc->setGold(pc->getGold() + theMap[r - 1][c + 1].getEnemy()->getGold());
            theMap[r - 1][c + 1].setState(State::Empty);
            td->notify(theMap[r - 1][c + 1]);
            int k = theMap[r - 1][c + 1].getEnemy()->getGold();
            result = result + " PC get " + std::to_string(k) + " gold.";
            if (theMap[r - 1][c + 1].getEnemy()->getCompass() == true) {
                theMap[r - 1][c + 1].setState(State::Compass);
                td->notify(theMap[r - 1][c + 1]);
            }
        }
    }
    else if ((direction == "nw") && ((theMap[r - 1][c - 1].getInfo().thing == State::Vampire)
        || (theMap[r - 1][c - 1].getInfo().thing == State::Werewolf) ||
        (theMap[r - 1][c - 1].getInfo().thing == State::Goblin) ||
        (theMap[r - 1][c - 1].getInfo().thing == State::Merchant) ||
        (theMap[r - 1][c - 1].getInfo().thing == State::Dragon) ||
        (theMap[r - 1][c - 1].getInfo().thing == State::Phoenix) ||
        (theMap[r - 1][c - 1].getInfo().thing == State::Troll))) {
        if (theMap[r - 1][c - 1].getInfo().thing == State::Merchant) attackMerchant = true;
        int i = theMap[r - 1][c - 1].getEnemy()->Combat(pc);
       
        std::string str;
        int live = theMap[r - 1][c - 1].getEnemy()->getHP();
        if (theMap[r - 1][c - 1].getInfo().thing == State::Werewolf) str = "W";
        if (theMap[r - 1][c - 1].getInfo().thing == State::Goblin) str = "N";
        if (theMap[r - 1][c - 1].getInfo().thing == State::Merchant) str = "M";
        if (theMap[r - 1][c - 1].getInfo().thing == State::Dragon) str = "D";
        if (theMap[r - 1][c - 1].getInfo().thing == State::Phoenix) str = "X";
        if (theMap[r - 1][c - 1].getInfo().thing == State::Troll) str = "T";
        if (theMap[r - 1][c - 1].getInfo().thing == State::Vampire) str = "V";
        result = "PC deals " + std::to_string(i) + " damge to " + str + " (" + std::to_string(live)
            + " HP).";

        if (theMap[r - 1][c - 1].getEnemy()->getHP() > 0) {
            int j = pc->Combat(theMap[r - 1][c - 1].getEnemy());
            result = result + " " + str + " deals " + std::to_string(j) + " damage to PC.";
        }
        else {
            pc->setGold(pc->getGold() + theMap[r - 1][c - 1].getEnemy()->getGold());
            theMap[r - 1][c - 1].setState(State::Empty);
            td->notify(theMap[r - 1][c - 1]);
            int k = theMap[r - 1][c - 1].getEnemy()->getGold();
            result = result + " PC get " + std::to_string(k) + " gold.";
            if (theMap[r - 1][c - 1].getEnemy()->getCompass() == true) {
                theMap[r - 1][c - 1].setState(State::Compass);
                td->notify(theMap[r - 1][c - 1]);
            }
        }
    }

    else if ((direction == "se") && ((theMap[r + 1][c + 1].getInfo().thing == State::Vampire)
        || (theMap[r + 1][c + 1].getInfo().thing == State::Werewolf) ||
        (theMap[r + 1][c + 1].getInfo().thing == State::Goblin) ||
        (theMap[r + 1][c + 1].getInfo().thing == State::Merchant) ||
        (theMap[r + 1][c + 1].getInfo().thing == State::Dragon) ||
        (theMap[r + 1][c + 1].getInfo().thing == State::Phoenix) ||
        (theMap[r + 1][c + 1].getInfo().thing == State::Troll))) {
        
        int i = theMap[r + 1][c + 1].getEnemy()->Combat(pc);
        
        if (theMap[r + 1][c + 1].getInfo().thing == State::Merchant) attackMerchant = true;
        std::string str;
        int live = theMap[r + 1][c + 1].getEnemy()->getHP();
        if (theMap[r + 1][c + 1].getInfo().thing == State::Werewolf) str = "W";
        if (theMap[r + 1][c + 1].getInfo().thing == State::Goblin) str = "N";
        if (theMap[r + 1][c + 1].getInfo().thing == State::Merchant) str = "M";
        if (theMap[r + 1][c + 1].getInfo().thing == State::Dragon) str = "D";
        if (theMap[r + 1][c + 1].getInfo().thing == State::Phoenix) str = "X";
        if (theMap[r + 1][c + 1].getInfo().thing == State::Troll) str = "T";
        if (theMap[r + 1][c + 1].getInfo().thing == State::Vampire) str = "V";
        result = "PC deals " + std::to_string(i) + " damge to " + str + " (" + std::to_string(live)
            + " HP).";

        if (theMap[r + 1][c + 1].getEnemy()->getHP() > 0) {
            int j = pc->Combat(theMap[r + 1][c + 1].getEnemy());
            result = result + " " + str + " deals " + std::to_string(j) + " damage to PC.";
        }
        else {
            pc->setGold(pc->getGold() + theMap[r + 1][c + 1].getEnemy()->getGold());
            theMap[r + 1][c + 1].setState(State::Empty);
            td->notify(theMap[r + 1][c + 1]);
            int k = theMap[r + 1][c + 1].getEnemy()->getGold();
            result = result + " PC get " + std::to_string(k) + " gold.";
            if (theMap[r + 1][c + 1].getEnemy()->getCompass() == true) {
                theMap[r + 1][c + 1].setState(State::Compass);
                td->notify(theMap[r + 1][c + 1]);
            }
        }
    }
    else if ((direction == "sw") && ((theMap[r + 1][c - 1].getInfo().thing == State::Vampire)
        || (theMap[r + 1][c - 1].getInfo().thing == State::Werewolf) ||
        (theMap[r + 1][c - 1].getInfo().thing == State::Goblin) ||
        (theMap[r + 1][c - 1].getInfo().thing == State::Merchant) ||
        (theMap[r + 1][c - 1].getInfo().thing == State::Dragon) ||
        (theMap[r + 1][c - 1].getInfo().thing == State::Phoenix) ||
        (theMap[r + 1][c - 1].getInfo().thing == State::Troll))) {
        
        int i = theMap[r + 1][c - 1].getEnemy()->Combat(pc);
        if (theMap[r + 1][c - 1].getInfo().thing == State::Merchant) attackMerchant = true;
        std::string str;
        int live = theMap[r + 1][c - 1].getEnemy()->getHP();
        if (theMap[r + 1][c - 1].getInfo().thing == State::Werewolf) str = "W";
        if (theMap[r + 1][c - 1].getInfo().thing == State::Goblin) str = "N";
        if (theMap[r + 1][c - 1].getInfo().thing == State::Merchant) str = "M";
        if (theMap[r + 1][c - 1].getInfo().thing == State::Dragon) str = "D";
        if (theMap[r + 1][c - 1].getInfo().thing == State::Phoenix) str = "X";
        if (theMap[r + 1][c - 1].getInfo().thing == State::Troll) str = "T";
        if (theMap[r + 1][c - 1].getInfo().thing == State::Vampire) str = "V";
        result = "PC deals " + std::to_string(i) + " damge to " + str + " (" + std::to_string(live)
            + " HP).";

        if (theMap[r + 1][c - 1].getEnemy()->getHP() > 0) {
            int j =pc->Combat(theMap[r + 1][c - 1].getEnemy());
            result = result + " " + str + " deals " + std::to_string(j) + " damage to PC.";
        }
        else {
            pc->setGold(pc->getGold() + theMap[r + 1][c - 1].getEnemy()->getGold());
            theMap[r + 1][c - 1].setState(State::Empty);
            td->notify(theMap[r + 1][c - 1]);
            int k = theMap[r + 1][c - 1].getEnemy()->getGold();
            result = result + " PC get " + std::to_string(k) + " gold.";
            if (theMap[r + 1][c - 1].getEnemy()->getCompass() == true) {
                theMap[r + 1][c - 1].setState(State::Compass);
                td->notify(theMap[r + 1][c - 1]);
            }
        }
    }
    else {
        return "The direction you attack has no enemy. Please reenter.";
    }
    State temp;
    if (direction == "no") {
        temp = theMap[r-1][c].getState();
        theMap[r-1][c].setState(State::None);
        moveEnemy();
        result += enemyAround(r,c);
        theMap[r-1][c].setState(temp);
    } else if (direction == "ne") {
        temp = theMap[r-1][c+1].getState();
        theMap[r-1][c+1].setState(State::None);
        moveEnemy();
        result += enemyAround(r,c);
        theMap[r-1][c+1].setState(temp);
    } else if (direction == "ea") {
        temp = theMap[r][c+1].getState();
        theMap[r][c+1].setState(State::None);
        moveEnemy();
        result += enemyAround(r,c);
        theMap[r][c+1].setState(temp);
    } else if (direction == "se") {
        temp = theMap[r+1][c+1].getState();
        theMap[r+1][c+1].setState(State::None);
        moveEnemy();
        result += enemyAround(r,c);
        theMap[r+1][c+1].setState(temp);
    } else if (direction == "so") {
        temp = theMap[r+1][c].getState();
        theMap[r+1][c].setState(State::None);
        moveEnemy();
        result += enemyAround(r,c);
        theMap[r+1][c].setState(temp);
    } else if (direction == "sw") {
        temp = theMap[r+1][c-1].getState();
        theMap[r+1][c-1].setState(State::None);
        moveEnemy();
        result += enemyAround(r,c);
        theMap[r+1][c-1].setState(temp);
    } else if (direction == "we") {
        temp = theMap[r][c-1].getState();
        theMap[r][c-1].setState(State::None);
        moveEnemy();
        result += enemyAround(r,c);
        theMap[r][c-1].setState(temp);
    } else if (direction == "nw") {
        temp = theMap[r-1][c-1].getState();
        theMap[r-1][c-1].setState(State::None);
        moveEnemy();
        result += enemyAround(r,c);
        theMap[r-1][c-1].setState(temp);
    }
    if (pc->getHP() <= 0) {
        int pcGold = pc->getGold();
        int score = 0;
        if (pc->getName() == "Human") {
            score = 1.5 * pcGold;
            if (pcGold % 2 == 0) {
            result += "Score: " + std::to_string(score) + "\n";
            } else if (pcGold % 2 == 1) {
            result += "Score: " + std::to_string(score) + ".5\n";
            }
        } else if(pc->getName() == "Orc") {
            score = pcGold / 2;
             if (pcGold % 2 == 0) {
            result += "Score: " + std::to_string(score) + "\n";
            } else if (pcGold % 2 == 1) {
            result += "Score: " + std::to_string(score) + ".5\n";
            }
        } else if(pc->getName() == "Dwarf") {
            score = 2 * pcGold;
            result += "Score: " + std::to_string(score) + "\n";
        } else if(pc->getName() == "Elves" || pc->getName() == "Saitama") {
            result += "Score: " + std::to_string(pc->getGold()) + "\n";
        }
        result += "You lose.\n";
       
        result += "GAME END\n";
    }
    return result;
}


void Map::resetMap() {

    pc->ReSet();
    delete td;
    td = nullptr;
    for(unsigned int i = 0 ; i < theMap.size(); ++i) {
        theMap[i].clear();
    }
    theMap.clear();
    for (size_t i = 0; i < row; ++i) {
        std::vector<Cell> c;
        for (size_t j = 0; j < col; ++j) {
            c.emplace_back(Cell(i,j,State::None));
        }
        theMap.emplace_back(c);
    }
    setting();
    init();
}


bool Map::checklive() {
    if (pc->getHP() == 0) {
        return false;
    }
    else {
        return true;
    }
}

bool Map::sixFloor() {
    return level == 6;
}
    
Map::~Map() {
    pc->ReSet();
    delete td;
    delete pc;
    for(unsigned int i = 0; i < theMap.size(); i += 1) {
        theMap[i].clear();
    }
    theMap.clear();

}


// method that prints current game status to players
void Map::printStatus(std::string message) {
    std::cout << "Race: " << pc->getName() << " " << "Gold: " << pc->getGold();
    std::cout << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "Floor: " << level << std::endl;
    std::cout << "HP: " << pc->getHP() << std::endl;
    std::cout << "Atk: " << pc->getAtk() << std::endl;
    std::cout << "Def: " << pc->getDef() << std::endl;
    std::cout << "Action: " << message << std::endl;
} 

std::ostream &operator<<(std::ostream &out, const Map &m) { 
    out << *m.td;
    return out;
}
