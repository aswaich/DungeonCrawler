#ifndef __WALL_H__
#define __WALL_H__

#include "cell.h"
#include <string>

class Wall :public Cell {
	std::string type;	//represents the type of wall that is here
	public:
	// ctor
	Wall(int r, int c, std::string type);
	//returns the string type
	std::string whatsHere();
	// returns a NULL pointer
	Character * getChar();
	// returns a NULL pointer
	Item * getItem();
	// the following do nothing
	void updateChar(Character * c);
	void updateItem(Item * i);
};

#endif
