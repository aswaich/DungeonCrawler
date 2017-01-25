#ifndef __DECBOOSTATK_H__
#define __DECBOOSTATK_H__

#include "DecorateEffect.h"

class DecBoostAtk : public DecorateEffect {
  public:
    DecBoostAtk(Character &playerChar);
    int getAtk();		// updates player attack
    int getDef();		// returns player defense
    int getHP();		// returns player HP
};

#endif
