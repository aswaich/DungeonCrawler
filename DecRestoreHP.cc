#include "DecRestoreHP.h"

using namespace std;

DecRestoreHP::DecRestoreHP(Character &playerChar) : DecorateEffect(playerChar) {}

// Return the current Attack of the Player Character
int DecRestoreHP::getAtk(){
	return playerChar.getAtk();
}

// Return the current Defense of the Player Character
int DecRestoreHP::getDef(){
	return playerChar.getDef();
}

// Restores up 10 HP of the Player Character; does not exceed the 
// max health of Player Characters race
int DecRestoreHP::getHP(){
	if (playerChar.getHP() < (playerChar.getMax() - 10)) {
	        if (playerChar.getHP() == 0) return 0;
		else return playerChar.getHP() + 10;
	}
	else return playerChar.getMax();
}
