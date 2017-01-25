#ifndef __WEREWOLF_H__
#define __WEREWOLF_H__

#include "Enemy.h"
#include <string>

class Werewolf : public Enemy {
  public:
    std::string whatAmI();		// Returns the letter "W" to represent Werewolf on the board
    std::string getRace();

    Werewolf(int MaxHP=120, int HP=120, int Atk=30, int Def=5, int Gold=0);
};

#endif
