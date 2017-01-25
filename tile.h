#ifndef __TILE_H__
#define __TILE_H__

#include "cell.h"
#include <string>

class Character;

class Tile: public Cell {
	// points to the character that is occupying the tile or is NULL
	Character * chara;
	// points to the Item that is occupying the tile or is NULL
	Item * it;
	// whats here if not a person or item
	std::string type;

	public:
	// ctor  given the character it hold or item or these are NULL
	Tile(int r, int c, int chamNum, Character *, Item *);
	// dtor
	~Tile();
	// replace Character
	void updateChar(Character * c);
	// replace Item
	void updateItem(Item * i);
	// update the type field
	void updateType(std::string s);

	// returns a string representing the tile on the board . empty or @ player or Enemy symbol or item symbol
	std::string whatsHere();

	// returns a pointer to the item
	Item * getItem();
	// return a pointer to the char that is here
	Character * getChar();
};

#endif
