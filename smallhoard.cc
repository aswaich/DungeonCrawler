#include "smallhoard.h"
#include "treasure.h"

#include <string>

using namespace std;

// ctor
SmallHoard::SmallHoard()
	:Treasure(2) {}

// return type
string SmallHoard::getType() {
	return "Small Hoard";
}


