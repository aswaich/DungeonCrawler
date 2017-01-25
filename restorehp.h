#ifndef __RESTOREHP_H__
#define __RESTOREHP_H__

#include "potion.h"

class RestoreHP: public Potion {
	public:
	static bool consumed;
	// ctor
	RestoreHP();
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
