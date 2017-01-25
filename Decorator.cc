#include "Decorator.h"

CharDecorator::CharDecorator(Character &playerChar) :
    Character(playerChar.getMax(), playerChar.getHP(), playerChar.getAtk(), playerChar.getDef(), playerChar.getGold()), playerChar(playerChar) {}

//dtor
CharDecorator::~CharDecorator() {
	delete &playerChar;
}
