#include "dragonhoard.h"
#include "treasure.h"
#include "cell.h"
#include "floor.h"
#include "character.h"

#include <cstdlib>
#include <string>

using namespace std;

// ctor
DragonHoard::DragonHoard()
	:Treasure(6), smaug(0) {}

// dtor, delete smaug
DragonHoard::~DragonHoard() {}

// set Smaug to contain a dragon pointer
void DragonHoard::setDragon(Cell * c) {
	smaug = c;
}

// returns the pointer to smaug
Cell * DragonHoard::getDragon() {
	return smaug;
}

// make smaug attack
string DragonHoard::guardMe() {
	return board->getPlayer()->defend(*(smaug->getChar()));
}

string DragonHoard::getType() {
	return "Dragon Hoard";
}

