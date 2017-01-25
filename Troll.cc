#include "Troll.h"

using namespace std;

string Troll::whatAmI(){
    return "T";
}

string Troll::getRace(){
    return "Troll";
}

Troll::Troll(int MaxHP, int HP, int Atk, int Def, int Gold) :
    Enemy(MaxHP, HP, Atk, Def, Gold) {}
