#include "Elf.h"

using namespace std;

string Elf::getRace(){
	return "Elf";
}

Elf::Elf(int MaxHP, int HP, int Atk, int Def, int Gold) :
    Player(MaxHP, HP, Atk, Def, Gold) {} 
