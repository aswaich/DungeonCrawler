#ifndef __DECPOISONHP_H__
#define __DECPOISONHP_H__

#include "DecorateEffect.h"

class DecPoisonHP : public DecorateEffect {
  public:
    DecPoisonHP(Character &playerChar);
    int getAtk();		// returns player attack
    int getDef();		// returns player defense
    int getHP();		// updates player HP
};

#endif
