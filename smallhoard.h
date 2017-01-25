#ifndef __SMALL_HOARD_H
#define __SMALL_HOARD_H

#include "treasure.h"

#include <string>

class SmallHoard: public Treasure {
	public:
	// ctor
	SmallHoard();
	// return type
	std::string getType();
};

#endif
