#include "normal.h"
#include "treasure.h"

#include <string>

using namespace std;

// ctor
Normal::Normal()
	:Treasure(1) {}

// returns the type
string Normal::getType() {
	return "Normal pile";
}

