#ifndef __BOOSTATK_H__
#define __BOOSTATK_H__

#include "potion.h"

class BoostAtk: public Potion {
	public:
	static bool consumed;
	// ctor sets fields
	BoostAtk();
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
