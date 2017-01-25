#ifndef __BLANK_H__
#define __BLANK_H__

#include "cell.h"
#include <string>

class Item;

class Blank: public Cell {
	public:
	// ctor
	Blank(int r, int c);
	// dtor
	~Blank();
	// returns an string with a space representing blank space
	std::string whatsHere();	
	// returns a NULL pointer
	Character * getChar();
	Item * getItem();
	// do nothing
	void updateChar(Character *);
	void updateItem(Item *);
};

#endif
