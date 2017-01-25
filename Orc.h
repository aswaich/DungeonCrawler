#ifndef __ORC_H__
#define __ORC_H__

#include "Player.h"
#include <string>

class Orc : public Player {
  public:
    std::string getRace();	// returns "Orc" for use by wrapper methods
    Orc(int MaxHP=180, int HP=180, int Atk=30, int Def=25, int Gold=0);
};

#endif
