#include "Orc.h"

using namespace std;

string Orc::getRace(){
    return "Orc";
}

Orc::Orc(int MaxHP, int HP, int Atk, int Def, int Gold) :
    Player(MaxHP, HP, Atk, Def, Gold) {} 
