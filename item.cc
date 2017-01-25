#include "item.h"

#include "floor.h"
#include <string>

using namespace std;

// ctor
Item::Item(string name): name(name) {
	board = Floor::getInstance(); 
}

// dtor
Item::~Item() {}

// returns name
string Item::whatAmI() {
	return name;
}

// sets consumed to false where needed;
void Item::vomit() {}

// returns true is we know what the type is 
bool Item::isConsumed() {
	return true;
}

// returns the Dragon pointer
Cell * Item::getDragon() {return NULL;}
// called when a player is too close to the Hoard to make the Dragon attack
string Item::guardMe() {
	return "";
}
// sets smaug
void Item::setDragon(Cell * c) {}


