#ifndef __ELF_H__
#define __ELF_H__

#include "Player.h"
#include <string>

class Elf : public Player {
  public:
    std::string getRace();	// Returns "Elf" for use by wrapper methods
    Elf(int MaxHP=140, int HP=140, int Atk=30, int Def=10, int Gold=0);
};

#endif
