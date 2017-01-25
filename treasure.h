#ifndef __TREASURE_H__
#define __TREASURE_H__

#include "item.h"
#include <string>

class Treasure: public Item {
	int value;	// represents the value of the gold
	// wraps the player
	void callwrapper();
	public:
	// ctor
	Treasure(int value);
	// dtor
	virtual ~Treasure()=0;
	// return value
	int getValue();	
	// grabs the gold
	void Consume();
};

#endif
