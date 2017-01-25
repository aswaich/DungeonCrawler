#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "Enemy.h"
#include <string>

// The Dragon is unique as an Enemy as it will only be hostile if a 
// player threatens to steal its treasure (ie player character is close
// to the Dragons DragonHoard)
class Dragon : public Enemy {
  public:

    // Returns the letter "D" to represent Dragon on the board
    std::string whatAmI();

    std::string getRace();

    Dragon(int MaxHP=150, int HP=150, int Atk=20, int Def=20, int Gold=0); 
};

#endif
