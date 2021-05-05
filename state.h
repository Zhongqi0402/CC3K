#ifndef STATE_H
#define STATE_H
/* State that can be placed in a cell are :
*       Enemy: Vampire, Werewolf, Goblin, Merchant, Dragon, Phoenix, Troll
*       Character
*       Potion
*       Map Sturcture: Stair, Horizontal Wall, Vertical Wall, Door, Hallway
*       other: Compass, BS, Gold 
*       Empty means it is a valid cell but there is nothing in the cell
*       None means it is not a valid cell
*/
enum class State {Vampire, Werewolf, Goblin, Merchant, Dragon, Phoenix, Troll, Character, RH, BA, BD, PH, WA, WD,
                Stair, HWall, VWall, Door, Hallway, BS, Normal, Horde, Mhorde, Dhorde, Empty, None, Compass};




#endif
