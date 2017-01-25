#include "DecDragonHoard.h"

DecDragonHoard::DecDragonHoard(Character &playerChar) :
    DecorateMoney(playerChar) {}


// Will increase the Players gold count by 6 if Human or Elf,
// or by 3 if an Orc, or 12 if a Dwarf
int DecDragonHoard::getGold(){
	if (playerChar.getRace() == "Orc") {			// Orcs receive half gold
		return playerChar.getGold() + 3;
	}
	else if (playerChar.getRace() == "Dwarf"){		// and Dwarves double. 
		return playerChar.getGold() + 12;
	}
	else return playerChar.getGold() + 6;
}
