#include "poisonhp.h"
#include "potion.h"
#include "floor.h"

#include <string>

bool PoisonHP::consumed = false;

using namespace std;

// ctor
PoisonHP::PoisonHP() 
	:Potion("poisonHP") {}


// return consumed
bool PoisonHP::isConsumed() {
	return consumed;
}

// set consumed to true
void PoisonHP::Consume() {
	consumed = true;
	callwrapper();
}

// sets consumed to false
void PoisonHP::vomit() {
	consumed = false;
}

// return the type if known
string PoisonHP::getType() {
	if (isConsumed()) {
		return "a PoisonHP potion";
	}
	else {
		return "an Unknown potion";
	}
}

