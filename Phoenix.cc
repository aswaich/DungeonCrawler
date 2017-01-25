#include "Phoenix.h"

using namespace std;

string Phoenix::whatAmI(){
    return "X";
}

string Phoenix::getRace(){
    return "Phoenix";
}

Phoenix::Phoenix(int MaxHP, int HP, int Atk, int Def, int Gold) :
    Enemy(MaxHP, HP, Atk, Def, Gold) {}
