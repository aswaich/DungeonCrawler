#ifndef __DWARF_H__
#define __DWARF_H__

#include "Player.h"
#include <string>

class Dwarf : public Player {
  public:
    std::string getRace();	// Returns "Dwarf" for use by wrapper methods
    Dwarf(int MaxHP=100, int HP=100, int Atk=20, int Def=30, int Gold=0);
};

#endif
