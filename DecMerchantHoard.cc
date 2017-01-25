#include "DecMerchantHoard.h"

DecMerchantHoard::DecMerchantHoard(Character &playerChar) :
    DecorateMoney(playerChar) {}

// Will increase the Players gold count by 4 if Human or Elf,
// or by 2 if an Orc, or 8 if a Dwarf
int DecMerchantHoard::getGold(){
	if (playerChar.getRace() == "Orc") {			// Orcs receive half gold
		return playerChar.getGold() + 2;
	}
	else if (playerChar.getRace() == "Dwarf"){		// and Dwarves double.
		return playerChar.getGold() + 8;
	}
	else return playerChar.getGold() + 4;
}
