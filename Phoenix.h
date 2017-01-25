#ifndef __PHOENIX_H__
#define __PHOENIX_H__

#include "Enemy.h"
#include <string>

class Phoenix : public Enemy {
  public:
    std::string whatAmI();		// Returns the letter "X" to represent Phoenix on the Board
    std::string getRace();

    Phoenix(int MaxHP=50, int HP=50, int Atk=35, int Def=20, int Gold=0);
};

#endif
