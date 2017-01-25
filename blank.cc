#include "blank.h"
#include "cell.h"

#include <string>

using namespace std;

// ctor
Blank::Blank(int r, int c)
	:Cell(r, c, 0) {}

// dtor
Blank::~Blank() {}

// returns a string with a space
string Blank::whatsHere() {
	return " ";
}

/// return a null pointer
Character * Blank::getChar() {
	return NULL;
}
Item * Blank::getItem() {
	return NULL;
}

// do nothing
void Blank::updateChar(Character * c) {}
void Blank::updateItem(Item * i) {}

