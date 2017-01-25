#ifndef __GOBLIN_H__
#define __GOBLIN_H__

#include "Enemy.h"
#include <string>

class Goblin : public Enemy {
  public:
    std::string whatAmI();		// Returns the letter "N" to represent Goblin on the board
    std::string getRace();

    Goblin(int MaxHP=70, int HP=70, int Atk=5, int Def=10, int Gold=0);
};

#endif
