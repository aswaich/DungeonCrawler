#ifndef __DECBOOSTDEF_H__
#define __DECBOOSTDEF_H__

#include "DecorateEffect.h"

class DecBoostDef : public DecorateEffect {
  public:
    DecBoostDef(Character &playerChar);
    int getAtk();		// returns player attack
    int getDef();		// updates player defense
    int getHP();		// returns player HP
};

#endif
