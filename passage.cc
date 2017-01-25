#include "passage.h"
#include "cell.h"
#include "character.h"

#include <string>

using namespace std;

// ctor
Passage::Passage(int r, int c)
	:Cell(r, c, 0), p(0) {}

// dtor
Passage::~Passage() {
	delete p;
}

// update the pointer
void Passage::updateChar(Character * c) {
		p = c;
}

// do nothing
void Passage::updateItem(Item * i) {}

// return the symbol of what's on the passage
string Passage::whatsHere() {
	if (p != NULL) {
		return p->whatAmI();
	}
	else {
		return "#";
	}
}

// return a pointer to the character
Character * Passage::getChar() {
	return p;
}

// return NULL
Item * Passage::getItem() {
	return NULL;
}
