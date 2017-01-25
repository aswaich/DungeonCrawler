#include "wounddef.h"
#include "potion.h"
#include "floor.h"

#include <string>

using namespace std;

bool WoundDef::consumed = false;


// ctor
WoundDef::WoundDef() 
	:Potion("woundDef") {}


// return consumed
bool WoundDef::isConsumed() {
	return consumed;
}

// set consumed to true
void WoundDef::Consume() {
	consumed = true;
	callwrapper();
}

// sets consumed to false
void WoundDef::vomit() {
	consumed = false;
}

// return type if known
string WoundDef::getType() {
	if (isConsumed()) {
		return "a WoundDef potion";
	}
	else {
		return "an Unknown potion";
	}
}

