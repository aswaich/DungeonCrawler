#include "Werewolf.h"

using namespace std;

string Werewolf::whatAmI(){
    return "W";
}

string Werewolf::getRace(){
    return "Werewolf";
}

Werewolf::Werewolf(int MaxHP, int HP, int Atk, int Def, int Gold) :
    Enemy(MaxHP, HP, Atk, Def, Gold) {}
