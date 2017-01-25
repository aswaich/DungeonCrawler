#include "DecorateMoney.h"

using namespace std;


DecorateMoney::DecorateMoney(Character &playerChar) : CharDecorator(playerChar) {}
// Return the Players Attack
int DecorateMoney::getAtk(){
	return playerChar.getAtk();
}

// Return the Players Defense
int DecorateMoney::getDef(){
	return playerChar.getDef();
}

// Return the Players HP
int DecorateMoney::getHP(){
	return playerChar.getHP();
}

// Return the symbol @ to represent Player on the board
string DecorateMoney::whatAmI(){
	return "@";
}

string DecorateMoney::getRace(){
	return playerChar.getRace();
}

string DecorateMoney::defend(Character &attacker) {
	return playerChar.defend(attacker);
}
