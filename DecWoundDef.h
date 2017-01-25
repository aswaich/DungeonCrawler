#ifndef __DECWOUNDDEF_H__
#define __DECWOUNDDEF_H__

#include "DecorateEffect.h"

class DecWoundDef : public DecorateEffect {
  public:
    DecWoundDef(Character &playerChar);
    int getAtk();		// returns player attack
    int getDef();		// updates player defense
    int getHP();		// returns player HP
};

#endif
