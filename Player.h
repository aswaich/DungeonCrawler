#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "character.h"
#include <string>

// The Player is the character controlled by the one playing the game
// This characters objective is to stay alive as they explore deeper
// into the dungeon, collecting items and slaying monsters along the
// way. May play as Human, Dwarf, Elf, or Orc.
class Player : public Character {
  public:

    // Returns the symbol "@" to represent Player on the board
    std::string whatAmI();

    // Method that will conduct combat between an attacker and the Player
    std::string defend(Character &attacker);
    
    Player(int MaxHP, int HP, int Atk, int Def, int Gold);
    virtual ~Player() {} 
};

#endif
