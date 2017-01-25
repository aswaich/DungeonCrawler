#include "DecBoostAtk.h"
using namespace std;

DecBoostAtk::DecBoostAtk(Character &playerChar) : DecorateEffect(playerChar) {}

// Add 5 Attack to the current player Attack stat
int DecBoostAtk::getAtk(){
	return playerChar.getAtk() + 5;
}

// Return the current Defense of the Player Character
int DecBoostAtk::getDef(){
	return playerChar.getDef();
}

// Return the current HP of the Player Character
int DecBoostAtk::getHP(){
	return playerChar.getHP();
}
