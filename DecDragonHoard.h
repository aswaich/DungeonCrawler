#ifndef __DECORATEDRAGONHOARD_H__
#define __DECORATEDRAGONHOARD_H__

#include "DecorateMoney.h"

class DecDragonHoard : public DecorateMoney {
  public:
    DecDragonHoard(Character &playerChar);
    int getGold();			// Will update the player gold count (effect based on race)
};

#endif
