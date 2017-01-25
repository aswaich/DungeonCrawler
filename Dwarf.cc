#include "Dwarf.h"

using namespace std;

string Dwarf::getRace(){
     return "Dwarf";
}

Dwarf::Dwarf(int MaxHP, int HP, int Atk, int Def, int Gold) :
    Player(MaxHP, HP, Atk, Def, Gold) {} 
