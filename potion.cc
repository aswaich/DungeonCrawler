#include "potion.h"
#include "floor.h"
#include <string>

Potion::Potion(std::string type): Item("P"), type(type) {}

//dtor
Potion::~Potion() {}
	
// wrap player on board using type
void Potion::callwrapper() {
	board->wrapPlayer(type);
}

