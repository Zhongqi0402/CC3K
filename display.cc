#include "display.h"
#include "cell.h"
#include "subject.h"
#include "info.h"
using namespace std;

std::vector<std::vector<char>> set(int r, int c) {
    std::vector<std::vector<char>> theDisplay;
    for (int i = 0; i < r; ++i) {
        std::vector<char> row;
        for (int j = 0; j < c; ++j) {
            row.emplace_back(' ');
        }
        theDisplay.emplace_back(row);
    }
    return theDisplay;
}

TextDisplay::TextDisplay(int r, int c)
  : theDisplay{set(r, c)}, r{r}, c{c} {}


void TextDisplay::notify(Subject & whoNotified) {

	int row = whoNotified.getInfo().row;

	int col = whoNotified.getInfo().col;
	
	State c = whoNotified.getInfo().thing;
	
	if (c == State::Vampire) {

		theDisplay[row][col] = 'V';
	}
	if (c == State::Werewolf) {

		theDisplay[row][col] = 'W';
	}

	if (c == State::Goblin) {

		theDisplay[row][col] = 'N';
	}
	if (c == State::Merchant) {

		theDisplay[row][col] = 'M';
	}
	if (c == State::Dragon) {

		theDisplay[row][col] = 'D';
	}
	if (c == State::Phoenix) {

		theDisplay[row][col] = 'X';
	}
	if (c == State::Troll) {

		theDisplay[row][col] = 'T';
	}
	if (c == State::Character) {

		theDisplay[row][col] = '@';
	}
	if (c == State::RH || c == State::BA || c == State::BD || c == State::PH || c == State::WA || c == State::WD) {

		theDisplay[row][col] = 'P';
	}
	if (c == State::Normal || c == State::Horde || c == State::Mhorde || c == State::Dhorde) {

		theDisplay[row][col] = 'G';
	}
	if (c == State::BS) {

		theDisplay[row][col] = 'B';
	}
	if (c == State::Stair) {

		theDisplay[row][col] = '\\';
	} 
	if (c == State::Door ) {
		theDisplay[row][col] = '+';
	}
	
	if(c == State::HWall) {
		theDisplay[row][col] = '-';
	}
	
	if (c == State::VWall) {
		theDisplay[row][col] = '|';
	}
	if(c == State::Hallway) {
		theDisplay[row][col] = '#';
	}
	if(c == State::Empty) {
		theDisplay[row][col] = '.';
	} 
	if(c == State::None) {
		theDisplay[row][col] = ' ';
	}
	if(c == State::Compass) {
		theDisplay[row][col] = 'C';
	}
}


std::ostream& operator<<(std::ostream& out, const TextDisplay& td) {
	for (int i = 0; i < td.r; ++i) {
		for (int j = 0; j < td.c; ++j) {
			out << td.theDisplay[i][j];
		}
		out << std::endl;
	}
	return out;
}
