#include "character.h"

// getters for the fields of Character
int Character::getMax(){ 
    return MaxHP;
}

int Character::getHP(){
    return HP;
}

int Character::getAtk(){
    return Atk;
}

int Character::getDef(){
    return Def;
}

int Character::getGold(){
    return Gold;
}

// Setters for the fields of character when taking damage, or when 
// starting a new floor
void Character::takeDamage(int damage) {
    if (HP > damage) {
	HP -= damage;
    }
    else HP = 0;
}

void Character::setmyHP(int myHP){
    HP = myHP;
}

void Character::setmyGold(int myGold){
    Gold = myGold;
}
 
// These functions are placeholders simply so that the functions may be 
// accessed in Merchant.
bool Character::isAngry(){
    return false;
}

void Character::setAnger() {}

void Character::setCalm() {}


Character::Character(int MaxHP, int HP, int Atk, int Def, int Gold) :
    MaxHP(MaxHP), HP(HP), Atk(Atk), Def(Def), Gold(Gold) {}

Character::~Character() {}
