#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "character.h"

// Enemies are non-playable characters that roam the map. This group consists
// of 5 hostile enemies (Werewolves, Vampires, Phoenixes, Trolls, and Goblins)
// and 2 situationally hostile enemies (Dragons when guarding their Hoard, or
// Merchants if a player attacks or slays a Merchant at any point in the game)
class Enemy : public Character {
  public:

    std::string defend(Character &attacker);

    Enemy(int MaxHP, int HP, int Atk, int Def, int Gold);
    virtual ~Enemy() {}
};

#endif
