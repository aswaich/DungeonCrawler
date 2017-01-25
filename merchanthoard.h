#ifndef __MERCHANT_HOARD_H__
#define __MERCHANT_HOARD_H__

#include "treasure.h"

#include <string>

class MerchantHoard: public Treasure {
	public:
	// ctor
	MerchantHoard();
	// return type
	std::string getType();
};

#endif
