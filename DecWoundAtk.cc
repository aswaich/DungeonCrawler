#include "DecWoundAtk.h"

using namespace std;

DecWoundAtk::DecWoundAtk(Character &playerChar) : DecorateEffect(playerChar) {}

// Subtract up to 5 from the current Attack of the Player Character.
// Attack cannot go below 0. If Player is an Elf, add 5 Attack.
int DecWoundAtk::getAtk(){
	if (playerChar.getRace() == "Elf") {
		return playerChar.getAtk() + 5;
	}
	if (playerChar.getAtk() > 5) {
		return playerChar.getAtk() - 5;
	}
	else return 0;
}

// Return the current Defense of the Player Character
int DecWoundAtk::getDef(){
	return playerChar.getDef();
}

// Return the current HP of the Player Character
int DecWoundAtk::getHP(){
	return playerChar.getHP();
}
