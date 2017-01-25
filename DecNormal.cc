#include "DecNormal.h"


DecNormal::DecNormal(Character &playerChar, bool slain) :
    DecorateMoney(playerChar), slain(slain) {}


// Will increase the Players gold count by 1 if Human or Elf,
// or by 1 if the second pile or monster Orc has picked up or 
// slain, or any combination of the two, or 2 if a Dwarf
int DecNormal::getGold(){
    if (playerChar.getRace() == "Orc") {		// Orcs receive half gold
	if (this->slain == true){
	    return playerChar.getGold() + 1;
	}
	else return playerChar.getGold();
    }
    else if (playerChar.getRace() == "Dwarf"){		// and Dwarves double.
	return playerChar.getGold() + 2;
    }
    else return playerChar.getGold() + 1;
}
