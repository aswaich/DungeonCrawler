#include "Goblin.h"

using namespace std;

string Goblin::whatAmI(){
    return "N";
}

string Goblin::getRace(){
    return "Goblin";
}

Goblin::Goblin(int MaxHP, int HP, int Atk, int Def, int Gold) :
    Enemy(MaxHP, HP, Atk, Def, Gold) {}
