#ifndef __DECORATEEFFECT_H__
#define __DECORATEEFFECT_H__

#include "Decorator.h"
#include <string>

class DecorateEffect : public CharDecorator {
  public:
    DecorateEffect(Character &playerChar);
    int getGold();			// Will simply return player gold
    std::string whatAmI();	// returns @ representing player
    std::string getRace();	// Returns the Players race

    std::string defend(Character &attacker);	    // returns player defend method
};

#endif
