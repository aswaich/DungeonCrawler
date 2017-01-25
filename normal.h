#ifndef __NORMAL_H__
#define __NORMAL_H__

#include "treasure.h"

class Normal: public Treasure {
	public:
	// ctor
	Normal();
	// return the type
	std::string getType();
};

#endif
