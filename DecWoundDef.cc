#include "DecWoundDef.h"

using namespace std;

DecWoundDef::DecWoundDef(Character &playerChar) : DecorateEffect(playerChar) {}

// Return the current Attack of the Player Character
int DecWoundDef::getAtk(){
	return playerChar.getAtk();
}

// Subtract up to 5 from the current Defense of the Player Character
// Defense cannot go below 0. If Player is an Elf, add 5 Defense
int DecWoundDef::getDef(){
	if (playerChar.getRace() == "Elf") {
		return playerChar.getDef() + 5;
	}	
	else if (playerChar.getDef() > 5) {
		return playerChar.getDef() - 5;
	}
	else return 0;
}

// Return the current HP of the Player Character
int DecWoundDef::getHP(){
	return playerChar.getHP();
}
