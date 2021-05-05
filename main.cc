#include <iostream>
#include <string>
#include "map.h"
#include "human.h"
#include "dwarf.h"
#include "elves.h"
#include "orc.h"
#include "saitama.h"
#include "state.h"
#include "info.h"
#include "fstream"
#include "cell.h"
#include "subject.h"
#include "potion.h"
#include "decorator.h"
#include "enemy.h"
#include "vampire.h"
#include "werewolf.h"
#include "troll.h"
#include "phoenix.h"
#include "goblin.h"
#include "dragon.h"
#include "merchant.h"

class InvalidCommand {};


int main(int argc, char *argv[]) {
    std::cin.exceptions(std::ios::eofbit | std::ios::failbit);
    bool reset = true;
   
    // Ask user to select character race
    while(reset == true) {
        reset = false;
        std::cout << "Please select your character race" << std::endl;
        std::cout << "h is for human(default)" << std::endl;
        std::cout << "d is for Dwarf" << std::endl;
        std::cout << "e is for Elves" << std::endl;
        std::cout << "o is for Orc" << std::endl;
        std::cout << "s is for Saitama(One-Punch Man)" << std::endl;
        std::string race;
        PC* pc = nullptr;
        try{
            std::cin >> race;
            if(race == "h") { 
                pc = new Human{140, 20, 20, 0, "Human", false, false}; 
            } else if(race == "d") { 
                pc = new Dwarf{100, 20, 30, 0, "Dwarf", false, false}; 
            } else if(race == "e") { 
                pc = new Elves{140, 30, 10, 0, "Elves", false, false}; 
            } else if(race == "o") { 
                pc = new Orc{180, 30, 25, 0, "Orc", false, false}; 
            } else if(race == "s") {
                pc = new Saitama{10000, 100, 100, 0, "Saitama", false, false};
            } else {
                throw InvalidCommand{};
            }
        }
        catch ( InvalidCommand& ){
            std::cout << "Invalid race. Please select from h, d, e, o, s." << std::endl;
            reset = true;
        }
        if(reset == true) { continue; }
        Map map{25, 79, 1, pc};
        map.setting();
        map.init();
        std::cout << map;
        map.printStatus("Enemies and Player are spawed to the map.");
        // read in user first interaction input
        std::string message;
        while (true) {
            std::cout << "Command: ";
            std::string cmd;
            std::cin >> cmd;
        
            if (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we" || cmd == "ne" ||
                cmd == "nw" || cmd == "se" || cmd == "sw") {
            
                message = map.movePC(cmd);
                if (map.sixFloor() == true) {
                    break;
                }
                std::cout << map;
                map.printStatus(message);
                if (map.checklive() == false) break;
            
            }
            else if (cmd == "u") {
                std::string dir;
                std::cin >> dir;
                message = map.usePotion(dir);
                std::cout << map;
                map.printStatus(message);
                if (map.checklive() == false) break;

            } 
            else if (cmd == "a") {
                std::string d;
                std::cin >> d;
                message = map.attackEnemy(d);
                std::cout << map;
                map.printStatus(message);
                if (map.checklive() == false) break;
            }
            else if(cmd == "r")  {
                reset = true;
                break;
            }
            else if(cmd == "q") {
                std::cout << "Defeat" << std::endl;
                break;
            }
        } 
    }
}
