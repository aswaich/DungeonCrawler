#include "boostatk.h"
#include "potion.h"
#include "floor.h"

#include <string>

bool BoostAtk::consumed = false;

using namespace std;

// ctor
BoostAtk::BoostAtk() 
	:Potion("boostAtk") {}


// return consumed
bool BoostAtk::isConsumed() {
	return consumed;
}

// set consumed to true
void BoostAtk::Consume() {
	consumed = true;
	callwrapper();
}

// sets consumed to false
void BoostAtk::vomit() {
	consumed = false;
}

string BoostAtk::getType() {
	if (isConsumed()) {
		return "a BoostAtk potion";
	}
	else {
		return "an Unknown potion";
	}
}
