#include "Vampire.h"

using namespace std;

string Vampire::whatAmI(){
	return "V";
}

string Vampire::getRace(){
    return "Vampire";
}

Vampire::Vampire(int MaxHP, int HP, int Atk, int Def, int Gold) :
    Enemy(MaxHP, HP, Atk, Def, Gold) {}
