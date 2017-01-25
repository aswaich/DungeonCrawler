#include "DecSmallHoard.h"

DecSmallHoard::DecSmallHoard(Character &playerChar) :
    DecorateMoney(playerChar) {}

// Will increase the Players gold count by 2 if Human or Elf,
// or by 1 if an Orc, or 4 if a Dwarf
int DecSmallHoard::getGold(){
	if (playerChar.getRace() == "Orc") {			// Orcs receive half gold
		return playerChar.getGold() + 1;
	}
	else if (playerChar.getRace() == "Dwarf"){		// and Dwarves double.
		return playerChar.getGold() + 4;
	}
	else return playerChar.getGold() + 2;
}
