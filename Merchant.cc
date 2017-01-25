#include "Merchant.h"

using namespace std;

bool Merchant::angry = false;

bool Merchant::isAngry(){
    return angry;
}

void Merchant::setAnger(){
    angry = true;
}

void Merchant::setCalm(){
    angry = false;
}

string Merchant::whatAmI(){
    return "M";
}

string Merchant::getRace(){
    return "Merchant";
}

Merchant::Merchant(int MaxHP, int HP, int Atk, int Def, int Gold) :
    Enemy(MaxHP, HP, Atk, Def, Gold) {}
