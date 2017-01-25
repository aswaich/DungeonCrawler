#include "DecorateEffect.h"

using namespace std;

DecorateEffect::DecorateEffect(Character &playerChar) :
    CharDecorator(playerChar) {}

int DecorateEffect::getGold(){
	return playerChar.getGold();	
}

string DecorateEffect::whatAmI(){
	return "@";
}

string DecorateEffect::getRace(){
	return playerChar.getRace();
}

string DecorateEffect::defend(Character &attacker) {
    return playerChar.defend(attacker);
}
