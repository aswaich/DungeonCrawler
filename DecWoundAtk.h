#ifndef __DECWOUNDATK_H__
#define __DECWOUNDATK_H__

#include "DecorateEffect.h"

class DecWoundAtk : public DecorateEffect {
  public:	
    DecWoundAtk(Character &playerChar);
    int getAtk();		// updates player attack
    int getDef();		// returns player defense
    int getHP();		// returns player HP
};

#endif
