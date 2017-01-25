#ifndef __TROLL_H__
#define __TROLL_H__

#include "Enemy.h"
#include <string>

class Troll : public Enemy {
  public:
    std::string whatAmI();		// Returns the letter "T" to represent troll on the board
    std::string getRace();

    Troll(int MaxHP=120, int HP=120, int Atk=25, int Def=15, int Gold=0);
};

#endif
