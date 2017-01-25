#ifndef __DECORATESMALLHOARD_H__
#define __DECORATESMALLHOARD_H__

#include "DecorateMoney.h"

class DecSmallHoard : public DecorateMoney {
  public:
    DecSmallHoard(Character &playerChar);
    int getGold();			// Will update the player gold count (effect based on race)
};

#endif
