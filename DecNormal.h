#ifndef __DECORATENORMAL_H__
#define __DECORATENORMAL_H__

#include "DecorateMoney.h"

class DecNormal : public DecorateMoney {
    bool slain;
  public:
    DecNormal(Character &playerChar, bool slain);
    int getGold();			// Will update the player gold count (effect based on race)
};

#endif
