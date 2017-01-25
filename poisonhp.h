#ifndef __POISONHP_H__
#define __POISONHP_H__

#include "potion.h"

class PoisonHP: public Potion {
	public:
	static bool consumed;
	// ctor
	PoisonHP();
	// returns consumed
	bool isConsumed();
	// sets consumed to true;
	void Consume();
	// returns type if known
	std::string getType();
	// sets consumed to false
	void vomit();
};

#endif
