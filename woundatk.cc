#include "woundatk.h"
#include "potion.h"
#include "floor.h"

#include <string>

using namespace std;

bool WoundAtk::consumed = false;


// ctor
WoundAtk::WoundAtk() 
	:Potion("woundAtk") {}


// return consumed
bool WoundAtk::isConsumed() {
	return consumed;
}

// set consumed to true
void WoundAtk::Consume() {
	consumed = true;
	callwrapper();
}

// sets consumed to false
void WoundAtk::vomit() {
	consumed = false;
}

// return type if known
string WoundAtk::getType() {
	if (isConsumed()) {
		return "a WoundAtk potion";
	}
	else {
		return "an Unknown potion";
	}
}

