#ifndef __DOORWAY_H__
#define __DOORWAY_H__

#include "cell.h"
#include <string>

class Character;

class Doorway: public Cell {
	Character * p;	// pointer to the player or NULL
	public:
	// ctor
	Doorway(int r, int c, Character * ch);
	// dtor
	~Doorway();
	// returns a string representing a doorway(+) or player(@)
	std::string whatsHere();
	// update the Character field
	void updateChar(Character * c);
	// do nothing
	void updateItem(Item * i);
	// returns a pointer to the Character
	Character * getChar();
	// return NULL
	Item * getItem();
};


#endif
