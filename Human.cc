#include "Human.h"

using namespace std;

string Human::getRace(){
    return "Human";
}

Human::Human(int MaxHP, int HP, int Atk, int Def, int Gold) :
    Player(MaxHP, HP, Atk, Def, Gold) {} 
