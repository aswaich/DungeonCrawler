#include "DecPoisonHP.h"

using namespace std;

DecPoisonHP::DecPoisonHP(Character &playerChar) : DecorateEffect(playerChar) {}

// Return the current Attack of the Player Character
int DecPoisonHP::getAtk(){
	return playerChar.getAtk();
}

// Return the current Defense of the Player Character
int DecPoisonHP::getDef(){
	return playerChar.getDef();
}

// Subtract up to 10 HP from the current HP of the Player Character.
// If the Character has less than 10 HP, updates HP to 0. If Player
// is an Elf, up to 10 HP is added.
int DecPoisonHP::getHP(){
	if (playerChar.getRace() == "Elf"){
		if (playerChar.getHP() < (playerChar.getMax() - 10)){
			if (playerChar.getHP() == 0) return 0;
			else return playerChar.getHP() + 10;
		}
		else return playerChar.getMax();
	}
	else if (playerChar.getHP() > 10){
		return playerChar.getHP() - 10;	
	}
	else return 0;
}
