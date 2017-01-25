#include "chamber.h"
#include "floor.h"
#include "cell.h"
#include "item.h"
#include "Dragon.h"
#include "Human.h"
#include "Dwarf.h"
#include "Elf.h"
#include "Orc.h"
#include "stairs.h"

#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iostream>

using namespace std;

// ctor
Chamber::Chamber() : freeCells(0) {
	theFloor = Floor::getInstance();
}

// place item thing in a random free square
void Chamber::placeItem(Item * thing) {
	unsigned int x = rand() % freeCells;
	freeCells--;
	empty[x]->updateItem(thing);
	taken.push_back(empty[x]);
	if (thing->getType() == "Dragon Hoard") {
		theFloor->addDHoard(empty[x]);
		// place dragon
		int y = rand() % freeCells;
		freeCells--;
		while(!empty[x]->isNeighbour(empty[y])) {
			y = rand() % freeCells;
		}
		thing->setDragon(empty[y]);
		// put the dragon in the cell
		Character * d = new Dragon;
		empty[y]->updateChar(d);
		// move cell from empty to taken
		taken.push_back(empty[y]);
		empty.erase(empty.begin() + y);
	}
	if (x == empty.size()) { x--; }
	empty.erase(empty.begin() + x);
}

// place Enemy in a random free square
void Chamber::placeEnemy(Character * enem) {
	int x = rand() % freeCells;
	freeCells--;
	empty[x]->updateChar(enem);
	taken.push_back(empty[x]);
	empty.erase(empty.begin() + x);
}

// place the player in a random free square
void Chamber::placePlayer(string race) {
	int x = rand() % freeCells;
	freeCells--;
	Character * c;
	if (race == "Human") {
		c = new Human;
	}
	else if (race == "Elf") {
		c = new Elf;
	}
	else if (race == "Orc") {
		c = new Orc;
	}
	else if (race == "Dwarf") {
		c = new Dwarf;
	}
	empty[x]->updateChar(c);
	theFloor->setPlayer(empty[x]);
	taken.push_back(empty[x]);
	empty.erase(empty.begin() + x);
}

// place the Stairs in a random free square, delete tile and replace with stairs
void Chamber::placeStairs() {
	int x = rand() % freeCells;
	freeCells--;
	empty[x]->updateType("\\");
	taken.push_back(empty[x]);
	empty.erase(empty.begin() + x);
}

// add c to empty
void Chamber::addEmpty(Cell *c) {
	empty.push_back(c);
	freeCells++;
}

// move c from empty to taken
void Chamber::makeTaken(Cell *c) {
	for (vector<Cell*>::iterator i = empty.begin() ; i != empty.end() ; i++) {
		if (c == *i) {
			taken.push_back(c);
			empty.erase(i);
			freeCells--;
			break;
		}
	}
}

// move c from taken to empty
void Chamber::makeEmpty(Cell * c) {
	for (vector<Cell*>::iterator i = taken.begin() ; i!= taken.end() ; i++) {
		if (c == *i) {
			empty.push_back(c);
			taken.erase(i);
			freeCells++;
			break;
		}
	}
}

// looks for a merchant and if it finds one returns true and calms the merchant
bool Chamber::calmMerchant() {
	for (vector<Cell*>::iterator i = taken.begin() ; i != taken.end() ; i++) {
		if((*i)->whatsHere() == "M") {
			(*i)->getChar()->setCalm();
			return true;
		}
	}
	return false;
}

// resets consumed for all potions that have been consumed
void Chamber::clearPotion() {
	for(vector<Cell*>::iterator i = taken.begin() ; i != taken.end() ; i++) {
		if ((*i)->whatsHere() == "P") {
			(*i)->getItem()->vomit();
		}
	}
}

// move the enemies (attack close player, or move randomly)
void Chamber::moveEnemys() {
	stringstream ss;
	bool attacked = false;
	vector <Cell *> movedTo;
	vector <Cell *> movedFrom;
	// go through all cells that contain something and look for Enemies
	for (vector<Cell*>::iterator i = taken.begin() ; i != taken.end() ; i++) {
		if ((*i)->whatsHere() == "V" || (*i)->whatsHere() == "W" || (*i)->whatsHere() == "N" || (*i)->whatsHere() == "X" || (*i)->whatsHere() == "T") {
			vector<Cell *> n = (*i)->getNeighbours();
			// iterate through neighbours and look for player
			if (!attacked) {
				for (vector<Cell*>::iterator j = n.begin() ; j != n.end()  ; j++) {
					if ((*j)->whatsHere() == "@") {
						ss << theFloor->getPlayer()->defend(*((*i)->getChar())) << " ";
						attacked = true;
						break;
					}
				}
			}
			// if no player move randomly
			if (!attacked) {
				int x = rand() % 8;
				while (n[x]->whatsHere() != ".") {
					x= rand() % 8;
				}
				
				n[x]->updateChar((*i)->getChar());
				(*i)->updateChar(NULL);	
				movedTo.push_back(n[x]);
				movedFrom.push_back(*i);
			}
			
		}
		else if ((*i)->whatsHere() == "M") {
			vector<Cell *> n = (*i)->getNeighbours();
			// itterate through neighbours and look for playet
			for (vector<Cell*>::iterator j = n.begin() ; j != n.end()  ; j++) {
				if ((*j)->whatsHere() == "@") {
					// if Angry then attack
					if ((*i)->getChar()->isAngry()) {
						ss << theFloor->getPlayer()->defend(*((*i)->getChar())) << " ";
						attacked = true;
						break;
					}
				}
			}
			if (!attacked) {
				int x = rand() % 8;
				while (n[x]->whatsHere() != ".") {
					x = rand() % 8;
				}
				n[x]->updateChar((*i)->getChar());
				(*i)->updateChar(NULL);
				movedTo.push_back(n[x]);
				movedFrom.push_back(*i);
			}
		}
		attacked = false;
	}
	for (vector<Cell *>::iterator i = movedFrom.begin() ; i != movedFrom.end() ; i++) {
		makeEmpty(*i);
	}
	for (vector<Cell *>::iterator i = movedTo.begin() ; i != movedTo.end() ; i++) {
		makeTaken(*i);
	}
	string output  = ss.str();
	if (output != "") {
		output += "\n";
	}
	theFloor->setAction(theFloor->getAction() + output);
}
