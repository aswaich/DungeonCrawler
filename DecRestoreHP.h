#ifndef __DECRESTOREHP_H__
#define __DECRESTOREHP_H__

#include "DecorateEffect.h"

class DecRestoreHP : public DecorateEffect {
  public:
    DecRestoreHP(Character &playerChar);
    int getAtk();		// return player attack
    int getDef();		// return player defense
    int getHP();		// updates player HP
};

#endif
