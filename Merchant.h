#ifndef __MERCHANT_H__
#define __MERCHANT_H__

#include "Enemy.h"
#include <string>

// Merchants are unique as an Enemy in that they are not hostile to
// the Player until the player has attacked or slain a Merchant. Up
// until that point, they will move as an Enemy, but will not attack
// a Player Character.
class Merchant : public Enemy {

    // angry is a class specific field; all merchants will be angry
    // if even one is attacked.
    static bool angry;

  public:

    // Checks if a Merchant is angry
    bool isAngry();

    // Sets angry field to true if a player has attacked a Merchant
    void setAnger();
    
    // Sets angry field of an ANGRY merchant to false;
    void setCalm();

    // Returns the letter "M" to represent a Merchant on the board
    std::string whatAmI();

    std::string getRace();

    Merchant(int MaxHP=30, int HP=30, int Atk=70, int Def=5, int Gold=0);
};

#endif
