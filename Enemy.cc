#include "Enemy.h"
#include <sstream>

using namespace std;

string Enemy::defend(Character &attacker) {
    ostringstream oss;
    int damage = ((100 * attacker.getAtk())/(100 + getDef()));

	// if damage is calculated imperfectly, add 1 to imitate a ceiling call 
	if (((100 * attacker.getAtk()) % (100 + getDef())) > 0) { damage++; }
   
    takeDamage(damage);
    oss << "You do " << damage << " damage to enemy " << getRace() << "!"
	<< " It has " << getHP() << " HP left! Don't you feel tough?";
    return oss.str();
}


Enemy::Enemy(int MaxHP, int HP, int Atk, int Def, int Gold) :
    Character(MaxHP, HP, Atk, Def, Gold) {}
