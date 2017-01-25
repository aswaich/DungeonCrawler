#include "merchanthoard.h"
#include "treasure.h"

#include <string>

using namespace std;

// ctor
MerchantHoard::MerchantHoard()
	:Treasure(4) {}

// return type
string MerchantHoard::getType() {
	return "Merchant Hoard";
}


