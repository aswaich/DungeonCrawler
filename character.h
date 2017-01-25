#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <string>

// A character is any Player or Enemy, and is distinguished by its fields
// In other words, all characters will have HP, Attack and Defense. Enemy characters do
// not carry gold, whereas the player character does. There will be a number of NPC 
// characters (enemies), but only one playable character (Player) 
class Character{
    int MaxHP;
    int HP;	
    int Atk;
    int Def;
    int Gold;

  public:

    // method to return the maxHP a character may have
    int getMax();

    // virtual method that will determine what the board representation of that character is
    virtual std::string whatAmI() = 0;

    // attacks the given character and wraps them in Damage
    virtual std::string defend(Character &attacker) = 0;
    
    // virtual setter that will set HP after taking damage
    void takeDamage(int damage);
    
    // Setters to set character health and gold
    void setmyHP(int myHP);
    void setmyGold(int myGold);

    // virtual getters that will retrieve the fields of the object upon which they are called
    virtual int getHP();
    virtual int getAtk();
    virtual int getDef();
    virtual int getGold();

    // Virtual method used to determine the race of a Character player. If called on enemy, 
    // will return the type of the Enemy (ie "Vampire")
    virtual std::string getRace() = 0;

    // Virtual methods to allow for use by the Merchant class
    virtual bool isAngry();
    virtual void setAnger();
    virtual void setCalm();

    Character(int MaxHP, int HP, int Atk, int Def, int Gold);
    virtual ~Character();
};

#endif
