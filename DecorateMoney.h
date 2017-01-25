#ifndef __DECORATEMONEY_H__
#define __DECORATEMONEY_H__

#include "Decorator.h"
#include <string>

class DecorateMoney : public CharDecorator {
  public:
    DecorateMoney(Character &playerChar);
    int getAtk();			// Will return current player attack
    int getDef();			// Will return current player defense
    int getHP();			// Will return current player HP
    std::string whatAmI();		// return @ symbol representing player
    std::string getRace();		// return the players race

    std::string defend(Character &attacker);	// returns player defend method
};

#endif
