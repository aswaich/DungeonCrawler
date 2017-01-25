#include "restorehp.h"
#include "potion.h"
#include "floor.h"

#include <string>

using namespace std;

bool RestoreHP::consumed = false;

// ctor
RestoreHP::RestoreHP() 
	:Potion("restoreHP") {}


// return consumed
bool RestoreHP::isConsumed() {
	return consumed;
}

// set consumed to true
void RestoreHP::Consume() {
	consumed = true;
	callwrapper();
}

// sets consumed to false
void RestoreHP::vomit() {
	consumed = false;
}

// returns type if known
string RestoreHP::getType(){
	if (isConsumed()) {
		return "a RestoreHP potion";
	}
	else {
		return "an Unknown potion";
	}
}

