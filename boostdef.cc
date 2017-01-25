#include "boostdef.h"
#include "potion.h"
#include "floor.h"

#include <string>

bool BoostDef::consumed = false;

using namespace std;

// ctor
BoostDef::BoostDef() 
	:Potion("boostDef") {}


// return consumed
bool BoostDef::isConsumed() {
	return consumed;
}

// set consumed to true
void BoostDef::Consume() {
	consumed = true;
	callwrapper();
}

// return type if known
string BoostDef::getType() {
	if (isConsumed()) {
		return "a BoostDef potion";
	}
	else {
		return "an Unknown potion";
	}
}

// sets consumed to false where needed;
void BoostDef::vomit() {
	consumed = false;
}
