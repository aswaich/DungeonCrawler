#include "cell.h"

#include <sstream>
#include <string>
#include "character.h"
#include "item.h"

using namespace std;

//ctor
Cell::Cell(int r, int c, int chamNum)
	:r(r), c(c), numNeighbours(0), chamberNum(chamNum) {}

//Dtor
Cell::~Cell() {}

// add a neighbour, if neighbours is already at max nothgin happens
void Cell::addNeighbour(Cell * nei) {
	if (numNeighbours < 8) {
		neighbours[numNeighbours] = nei;
		numNeighbours++;
	}
}

// update Item field
void Cell::updateItem(Item * it) {}

// update Character field
void Cell::updateChar(Character * ch) {}

// update the type field
void Cell::updateType(string s) {}



// get the column of the cell
int Cell::getCol() {
	return c;
}

// get the row of the Cell
int Cell::getRow() {
	return r;
}

// returns true if n is a neighbour of the Cell
bool Cell::isNeighbour(Cell * n) {
	for (int i = 0 ; i < numNeighbours ; i++) {
		if (n == neighbours[i]) return true;
	}
	return false;
}


// returns a pointer to the Character that is on the cell or NULL if there is none
Character * Cell::getChar() {return NULL;}
// returns a pointer to the item in the cell or NULL
Item * Cell::getItem() {return NULL;}

// takes in a number and returns the direction that number corresponds to (based on how neighbours are added)
string getDirection(int x) {
	if (x == 1) return "southwest";
	else if (x == 2) return "northwest";
	else if (x == 3) return "south";
	else if (x == 4) return "north";
	else if (x == 5) return "southeast";
	else if (x == 6) return "northeast";
	else if (x == 7) return "east";
	else if (x == 8) return "west";
}

// returns a string describing whats in the surrounding cells
string Cell::checkSurroundings() {
	bool something = false;
	bool anything = false;
	stringstream ss;
	ss << "There is ";
	vector<Cell*> around = getNeighbours();
	int count = 1;
	for (vector<Cell*>::iterator i= around.begin() ; i != around.end() ; i++) {
		if((*i)->whatsHere() == "V") {
			ss << " a Vampire to the ";
			something = true;
			anything = true;
		}
		else if ((*i)->whatsHere() == "W") {
			ss << " a Werewolf to the ";
			something = true;
			anything = true;
		}
		else if ((*i)->whatsHere() == "N") {
			ss << " a Goblin to the ";
			something = true;
			anything = true;
		}
		else if ((*i)->whatsHere() == "M") {
			if ((*i)->getChar()->isAngry()) {
				ss << " an angry looking Merchant to the ";
			}
			else {
				ss << " a Merchant to the ";
			}
			something = true;
			anything = true;
		}
		else if ((*i)->whatsHere() == "X") {
			ss << " a Phoenix to the ";
			something = true;
			anything = true;
		}
		else if ((*i)->whatsHere() == "T") {
			ss << " a Troll to the ";
			something = true;
			anything = true;
		}
		else if ((*i)->whatsHere() == "D") {
			ss << " a Dragon to the ";
			something = true;
			anything = true;
		}
		else if ((*i)->whatsHere() == "P") {
			ss << (*i)->getItem()->getType();
			ss << " to the ";
			something = true;
			anything = true;
		}
		else if ((*i)->whatsHere() == "G") {
			ss << "a " << (*i)->getItem()->getType() << " to the ";
			something = true;
			anything = true;
		}
		if (something) {
			ss << getDirection(count) << ",";
		}
		something = false;
		count++;
	}
	if (anything) {
		ss << " what will you do next?";
	}
	else {
		ss << " nothing around you... or is there."; 
	}
	return ss.str();
}

// returns a vector of the neighbours
vector<Cell*> Cell::getNeighbours() {
	vector<Cell*> neigh;
	for (int i =0 ; i < numNeighbours ; i++) {
		neigh.push_back(neighbours[i]);
	}
	return neigh;
}

// return the chamber number
int Cell::getChamNum() {
	return chamberNum;
}
