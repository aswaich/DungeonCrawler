#include "Player.h"
#include <cstdlib>
#include <sstream>

using namespace std;

string Player::whatAmI(){
	return "@";
}

string Player::defend(Character &attacker) {
    ostringstream oss;
    int hit = rand() % 2;
    if (hit == 0) {
	int damage =(100 * attacker.getAtk())/(100 + getDef());

        // if damage is calculated imperfectly, add 1 to imitate a ceiling call 
	if (((100 * attacker.getAtk()) % (100 + getDef())) > 0) { damage++; }

	takeDamage(damage);
	oss << attacker.getRace() << " hits you for " << damage << " damage!"
	    << " You have " << getHP() << " HP left!"; 
 
    } else {
	oss << attacker.getRace() << " totally misses it's attack! What a dope!"
	    << " You laugh at " << attacker.getRace() << " and make it cry.";
    }
    return oss.str();
}

Player::Player(int MaxHP, int HP, int Atk, int Def, int Gold) :
    Character (MaxHP, HP, Atk, Def, Gold) {}
