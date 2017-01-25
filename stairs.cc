#include "stairs.h"
#include "cell.h"

#include <string>

using namespace std;

// ctor
Stairs::Stairs(int r, int c, int chamNum)
	: Cell(r, c, chamNum) {}

// dtor
Stairs::~Stairs() {}
// returns \ representing the stairs
string Stairs::whatsHere() {
	return "\\";
}

// returns a NULL pointer
Character * Stairs::getChar() {
	return NULL;
}
Item * Stairs::getItem() {
	return NULL;
}

// do nothing
void Stairs::updateChar(Character * c) {}
void Stairs::updateItem(Item * i) {}
