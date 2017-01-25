#ifndef __STAIRS_H__
#define __STAIRS_H__

#include "cell.h"
#include <string>

class Stairs: public Cell {
	public:
	// ctor
	Stairs(int r, int c, int chamNum);
	//dtor
	~Stairs();
	// returns a \ representing the stairs on the board
	std::string whatsHere();
	// returns a NULL pointer
	Character * getChar();
	Item * getItem();
	// do nothing
	void updateChar(Character *);
	void updateItem(Item *);
};

#endif
