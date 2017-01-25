#include "treasure.h"
#include "item.h"

#include <string>
#include "floor.h"

using namespace std;

// ctor
Treasure::Treasure(int value) 
	: Item("G"), value(value) {}

// dtor
Treasure::~Treasure() {}
// get Value
int Treasure::getValue() {
	return value;
}

// wrap the player
void Treasure::callwrapper() {
	board->wrapPlayer(value);
}

// consume the gold
void Treasure::Consume() {
	callwrapper();
}

