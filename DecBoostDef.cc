#include "DecBoostDef.h"
using namespace std;

DecBoostDef::DecBoostDef(Character &playerChar) : DecorateEffect(playerChar) {}

// Return the current Attack of the Player Character
int DecBoostDef::getAtk(){
	return playerChar.getAtk();
}

// Add 5 Defense to the current Player Defense Stat
int DecBoostDef::getDef(){
	return playerChar.getDef() + 5;
}

// Return the current HP of the Player Character
int DecBoostDef::getHP(){
	return playerChar.getHP();
}
