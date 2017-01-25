#ifndef __BOOSTDEF_H__
#define __BOOSTDEF_H__

#include "potion.h"

class BoostDef: public Potion {
	public:
	static bool consumed;
	//ctor 
	BoostDef();
	// returns consumed
	bool isConsumed();
	// sets consumed to true
	void Consume();
	// return type if known
	std::string getType();
	// sets consumed to false where needed;
	void vomit();
};

#endif
