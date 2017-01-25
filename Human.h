#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "Player.h"
#include <string>

class Human : public Player {
  public:
    std::string getRace();	// Returns "Human" for use by wrapper methods
    Human(int MaxHP=140, int HP=140, int Atk=20, int Def=20, int Gold=0);
};

#endif
