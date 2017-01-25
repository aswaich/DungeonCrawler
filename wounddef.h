#ifndef __WOUNDDEF_H__
#define __WOUNDDEF_H__

#include "potion.h"

class WoundDef: public Potion {
	public:
	static bool consumed;
	// ctor
	WoundDef();
	// returns consumed
	bool isConsumed();
	// sets consumed to true
	void Consume();
	// return type if known
	std::string getType();
	// sets consumed to false
	void vomit();
};


#endif
