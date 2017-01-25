#ifndef __WOUNDATK_H__
#define __WOUNDATK_H__

#include "potion.h"

class WoundAtk: public Potion {
	public:
	static bool consumed;	// true if this type of potion has been consumed
	//ctor, sets consumed to false and sets other fields
	WoundAtk();
	bool isConsumed();	// returns consumed
	void Consume(); 	// sets consumed to true
	// return type if known
	std::string getType();
	// sets consumed to false
	void vomit();
};

#endif
