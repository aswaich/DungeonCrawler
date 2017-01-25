#ifndef __VAMPIRE_H__
#define __VAMPIRE_H__

#include "Enemy.h"
#include <string>

class Vampire : public Enemy {
  public:
    std::string whatAmI();      // Returns the letter "V" to represent Vampire on the board
    std::string getRace();

    Vampire(int MaxHP=50, int HP=50, int Atk=25, int Def=25, int Gold=0);
};

#endif
