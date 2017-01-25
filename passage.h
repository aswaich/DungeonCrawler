#ifndef __PASSAGE_H__
#define __PASSAGE_H__

#include "cell.h"
#include <string>

class Passage: public Cell {
	Character * p;	// pointer to the player or Null
	public:
	// ctor
	Passage(int r, int c);
	// dtor
	~Passage();
	// update character pointer
	void updateChar(Character * p);
	// do nothing
	void updateItem(Item *);
	// returns a string # representing the passage or @ representing player on the board
	std::string whatsHere();
	// returns a pointer to the Character
	Character * getChar();
	// return NULL
	Item * getItem();
};

#endif
