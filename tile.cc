#include "cell.h"
#include "tile.h"
#include "character.h"

#include <string>
#include "item.h"

using namespace std;

// ctor
Tile::Tile(int r, int c, int chamNum, Character * ch, Item * i)
	:Cell(r, c, chamNum), chara(ch), it(i), type(".") {}

// return symbol of what's in the square
string Tile::whatsHere() {
	if (chara != NULL) {
		return chara->whatAmI();
	}
	else if (it != NULL) {
		return it->whatAmI();
	}
	else {
		return type;
	}
}

// dtor
Tile::~Tile() {
	delete chara;
	delete it;
}

// update the type field
void Tile::updateType(string s) {
	type = s;
}


// update the character field
void Tile::updateChar(Character * c) {
	chara = c;
}

// update the Item Field
void Tile::updateItem(Item * i) {
	it = i;
}

// return character pointer
Character * Tile::getChar() {
	return chara;
}

// returns a pointer to the Item
Item * Tile::getItem() {
	return it;
}
