#include "cell.h"
#include "wall.h"

#include <string>

using namespace std;

// ctor defines the type of wall | or -
Wall::Wall(int r, int c, string type)
	: Cell(r, c, 0), type(type) {}

// return type
string Wall::whatsHere() {
	return type;
}

// return NULL, no character
Character * Wall::getChar() {
	return NULL;
}

// returns NULL, no item
Item * Wall::getItem() {
	return NULL;
}

// do nothing
void Wall::updateChar(Character * c) {}
void Wall::updateItem(Item * i) {}
