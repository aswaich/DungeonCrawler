#ifndef __DECORATEMERCHANTHOARD_H__
#define __DECORATEMERCHANTHOARD_H__

#include "DecorateMoney.h"

class DecMerchantHoard : public DecorateMoney {
  public:
    DecMerchantHoard(Character &playerChar);
    int getGold();			// Will update the player gold count (effect based on race)
};

#endif
