#include "Dragon.h"

using namespace std;

string Dragon::whatAmI(){
    return "D";
}

string Dragon::getRace(){
    return "Dragon";
}

Dragon::Dragon(int MaxHP, int HP, int Atk, int Def, int Gold) :
    Enemy(MaxHP, HP, Atk, Def, Gold) {}
