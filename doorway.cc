#include "doorway.h"
#include "character.h"

#include <string>

using namespace std;

// ctor
Doorway::Doorway(int r, int c, Character * ch)
	:Cell(r, c, 0), p(ch) {}

// dtor
Doorway::~Doorway() {
	delete p;
}

// return a string representing a doorway or a player
string Doorway::whatsHere() {
	if (p != NULL) {
		return p->whatAmI();
	}
	else {
		return "+";
	}
}

// update the character field
void Doorway::updateChar(Character * c) {
	p = c;
}

// do nothing
void Doorway::updateItem(Item * i) {}

// returns a pointer to the character
Character * Doorway::getChar() {
	return p;
}

// return NULL
Item * Doorway::getItem() {
	return NULL;
}

