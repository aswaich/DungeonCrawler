#include "allincludes.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;


// set instance
Floor * Floor::instance = NULL;


//default ctor
Floor::Floor(): c(0), p(0), numRow(0), numCol(0), action(""), normalGoldCount(0) {}

//dtor
Floor::~Floor() {
	p = NULL;
	for (int i =0 ; i< numRow ; i++) {
		for (int j = 0 ; j < numCol  ; j++) {
			delete c[i][j];
		}
		delete [] c[i];
	}
	delete [] c;
	for (int i = 0 ; i < 5 ; i++) {
		delete rooms[i];
	}
}
// getting an instance of the floor
Floor * Floor::getInstance() {
	if (instance == NULL) {
		instance = new Floor;
		atexit(cleanup);
	}
	return instance;
}

// clean up
void Floor::cleanup() {
	delete instance;
}

// sets the first merchant it finds to be calm
void Floor::calmMerchants() {
	bool calmed = false;
	for (int i = 0 ; i < 5; i++) {
		calmed = rooms[i]->calmMerchant();
		if (calmed) break;
	}
}

// sets all the potions consumed to be false
void Floor::clearPotions() {
	for (int i = 0 ; i < 5 ; i++) {
		rooms[i]->clearPotion();
	}
}

// returns a vector containing the dragonHoards
vector <Cell*> Floor::getDHoards() {
	return DHoards;
}

// adds a cell to DHoards
void Floor::addDHoard(Cell *dh) {
	DHoards.push_back(dh);
}

// get the action string
string Floor::getAction() {
	return action;
}

// get Player
Character * Floor::getPlayer() {
	return p->getChar();
}

// set the player
void Floor::setPlayer(Cell * ch) {
	p = ch;
}

// set the action string
void Floor::setAction(string s) {
	action = s;
}

// create the Board, if given a file start on a certain line depending on level
void Floor::createBoard(int rows, int columns, int l, string race,  string file) {
	if (c != NULL) {
		p = NULL;
		for (int i =0 ; i< numRow ; i++) {
			for (int j = 0 ; j < numCol  ; j++) {
				delete c[i][j];
			}
			delete [] c[i];
		}
		delete [] c;
		c = NULL;
		for (int i = 0 ; i < 5 ; i++) {
			delete rooms[i];
		}
	}
	DHoards.clear();
	// create floor array
	level = l;
	numRow = rows;
	numCol = columns;
	c = new Cell**[rows];
	for (int i = 0 ; i < rows ; i++) {
		c[i] = new Cell*[columns];
	}

	// create Chambers array
	for (int i = 0 ; i < 5 ; i++) {
		rooms[i] = new Chamber;
	}	
	// create a base floor from file baseFloor.txt
	ifstream base("baseFloor.txt");
	string line;
	// read in from the file one row at a time
	for (int ro = 0 ; ro < rows ; ro++) {
		getline(base, line);
		stringstream ss(line);
		char place;
		// go through entire line
		for (int co = 0 ; co < columns ; co++) {
			ss.get(place);
			if (place == ' ') {
				c[ro][co] = new Blank(ro, co);
			} 
			else if (place == '|') {
				c[ro][co] = new Wall(ro, co, "|");
			}
			else if (place == '-') {
				c[ro][co] = new Wall(ro, co, "-");
			}
			else if (place == '#') {
				c[ro][co] = new Passage(ro, co);
			}
			else if (place == '+') {
				c[ro][co] = new Doorway(ro, co, NULL);
			}
			// numbers represent the chambers
			else if (place == '1') {
				c[ro][co]= new Tile(ro, co, 1, NULL, NULL);
				rooms[0]->addEmpty(c[ro][co]);
			}
			else if (place == '2') {
				c[ro][co] = new Tile(ro, co, 2, NULL, NULL);
				rooms[1]->addEmpty(c[ro][co]);
			}
			else if (place == '3') {
				c[ro][co] = new Tile(ro, co, 3, NULL, NULL);
				rooms[2]->addEmpty(c[ro][co]);
			}
			else if (place == '4') {
				c[ro][co] = new Tile(ro, co, 4, NULL, NULL);
				rooms[3]->addEmpty(c[ro][co]);
			}
			else if (place == '5') {
				c[ro][co] = new Tile(ro, co, 5, NULL, NULL);
				rooms[4]->addEmpty(c[ro][co]);
			}
		}
	}

	// add all the neighbours to tile cells
	for (int ro = 0 ; ro < rows ; ro++) {
		for (int co = 0 ; co < columns ; co++) {
			if (c[ro][co]->whatsHere() == "." || c[ro][co]->whatsHere() == "#" || c[ro][co]->whatsHere() == "+") {
				for( int off = -1 ; off < 2 ; off++) {	
						c[ro][co]->addNeighbour(c[ro+1][co+off]);
						c[ro][co]->addNeighbour(c[ro-1][co+off]);
				}
				c[ro][co]->addNeighbour(c[ro][co+1]);
				c[ro][co]->addNeighbour(c[ro][co-1]);
			}
		}
	}

	// figure out if you are given input or if you are doing random
	if (file == "default") {
		spawnPlayerAndStairs(race);
		spawnItems();
		spawnEnemys();
		
	}
	else {
		ifstream f(file.c_str());
		int jump = l-1 * (rows) + 1;
		string s;
		int chamNum;
		// jump to correct line in file
		for (int i = 0 ; i < jump ; i++) {
			getline(f, s);
		}
		for (int ro = 0 ; ro < rows ; ro++) {
			getline(f, s);
			stringstream ss(s);
			char place;
			// go through entire line
			for (int co = 0 ; co < columns ; co++) {
				ss.get(place);
				if (place == '@') {
					Character * you = NULL;
					if (race == "Human") {
						you = new Human;
					}
					else if (race == "Elf") {
						you = new Elf;
					}
					else if (race == "Orc") {
						you = new Orc;
					}
					else if (race == "Dwarf") {
						you = new Dwarf;
					}
					c[ro][co]->updateChar(you);
					p = c[ro][co]; 
					chamNum = c[ro][co]->getChamNum();
					rooms[chamNum-1]->makeTaken(c[ro][co]);
				}
				else if (place == 'V') {
					Character * v = new Vampire();
					c[ro][co]->updateChar(v); 
					chamNum = c[ro][co]->getChamNum();
					rooms[chamNum-1]->makeTaken(c[ro][co]);
				}
				else if (place == 'W') {
					Character * w = new Werewolf();
					c[ro][co]->updateChar(w); 
					chamNum = c[ro][co]->getChamNum();
					rooms[chamNum-1]->makeTaken(c[ro][co]);
				}
				else if (place == 'N') {
					Character * n = new Goblin();
					c[ro][co]->updateChar(n); 
					chamNum = c[ro][co]->getChamNum();
					rooms[chamNum-1]->makeTaken(c[ro][co]);
				}
				else if (place == 'M') {
					Character * m = new Merchant();
					c[ro][co]->updateChar(m); 
					chamNum = c[ro][co]->getChamNum();
					rooms[chamNum-1]->makeTaken(c[ro][co]);
				}
				else if (place == 'D') {
					Character * d = new Dragon();
					c[ro][co]->updateChar(d); 
					chamNum = c[ro][co]->getChamNum();
					rooms[chamNum-1]->makeTaken(c[ro][co]);
				}
				else if (place == 'X') {
					Character * x = new Phoenix();
					c[ro][co]->updateChar(x); 
					chamNum = c[ro][co]->getChamNum();
					rooms[chamNum-1]->makeTaken(c[ro][co]);
				}
				else if (place == 'T') {
					Character * t = new Troll();
					c[ro][co]->updateChar(t); 
					chamNum = c[ro][co]->getChamNum();
					rooms[chamNum-1]->makeTaken(c[ro][co]);
				}
				else if (place == '0') {
					Item * p = new RestoreHP;
					c[ro][co]->updateItem(p); 
					chamNum = c[ro][co]->getChamNum();
					rooms[chamNum-1]->makeTaken(c[ro][co]);
				}
				else if (place == '1') {
					Item * p = new BoostAtk;
					c[ro][co]->updateItem(p); 
					chamNum = c[ro][co]->getChamNum();
					rooms[chamNum-1]->makeTaken(c[ro][co]);
				}
				else if (place == '2') {
					Item * p = new BoostDef;
					c[ro][co]->updateItem(p); 
					chamNum = c[ro][co]->getChamNum();
					rooms[chamNum-1]->makeTaken(c[ro][co]);
				}
				else if (place == '3') {
					Item * p = new PoisonHP;
					c[ro][co]->updateItem(p); 
					chamNum = c[ro][co]->getChamNum();
					rooms[chamNum-1]->makeTaken(c[ro][co]);
				}
				else if (place == '4') {
					Item * p = new WoundAtk;
					c[ro][co]->updateItem(p); 
					chamNum = c[ro][co]->getChamNum();
					rooms[chamNum-1]->makeTaken(c[ro][co]);
				}
				else if (place == '5') {
					Item * p = new WoundDef;
					c[ro][co]->updateItem(p); 
					chamNum = c[ro][co]->getChamNum();
					rooms[chamNum-1]->makeTaken(c[ro][co]);
				}
				else if (place == '6') {
					Item * g = new Normal;
					c[ro][co]->updateItem(g); 
					chamNum = c[ro][co]->getChamNum();
					rooms[chamNum-1]->makeTaken(c[ro][co]);
				}
				else if (place == '7') {
					Item * g = new SmallHoard;
					c[ro][co]->updateItem(g); 
					chamNum = c[ro][co]->getChamNum();
					rooms[chamNum-1]->makeTaken(c[ro][co]);
				}
				else if (place == '8') {
					Item * g = new MerchantHoard;
					c[ro][co]->updateItem(g); 
					chamNum = c[ro][co]->getChamNum();
					rooms[chamNum-1]->makeTaken(c[ro][co]);
				}
				else if (place == '9') {
					Item * g = new DragonHoard;
					c[ro][co]->updateItem(g);
					DHoards.push_back(c[ro][co]);
					chamNum = c[ro][co]->getChamNum();
					rooms[chamNum-1]->makeTaken(c[ro][co]);

				}
				else if (place == '\\') {
					c[ro][co]->updateType("\\");
					chamNum = c[ro][co]->getChamNum();
					rooms[chamNum-1]->makeTaken(c[ro][co]);

					/*int cn = c[ro][co]->getChamNum();
					delete c[ro][co];
					c[ro][co] = new Stairs(ro, co, cn);
*/
				}
							}
		}
		// must associate Dragons with DragonHoards
		for(vector<Cell*>::iterator i=DHoards.begin() ; i != DHoards.end() ; i++) {
			vector<Cell*> possible = (*i)->getNeighbours();
			for (vector<Cell*>::iterator j = possible.begin() ; j != possible.end() ; j++) {
				if((*j)->whatsHere() == "D") {
					(*i)->getItem()->setDragon(*j);
				}
			}
		}
	}
}

// wrap the player in potion type
void Floor::wrapPlayer(string type) {
	Character * person = p->getChar();
	if (type == "boostAtk") {
		person = new DecBoostAtk(*person);
	}
	else if (type == "boostDef") {
		person = new DecBoostDef(*person);
	}
	else if (type == "woundAtk") {
		person = new DecWoundAtk(*person);
	}
	else if (type == "woundDef") {
		person = new DecWoundDef(*person);	
	}
	else if (type == "poisonHP") {
		person = new DecPoisonHP(*person);
	}
	else if (type == "restoreHP") {
		person= new DecRestoreHP(*person);
	}
	p->updateChar(person);
}

// wrap the player in gold value
void Floor::wrapPlayer(int value) {
	Character * person = getPlayer();
	if (value == 1) {
		if (getPlayer()->getRace() == "Orc") {
			if(normalGoldCount%2 == 0) {
				person = new DecNormal(*person, true);
			}
		}
		else {
			person = new DecNormal(*person, true); 
		}
	}
	else if (value == 2) {
		person = new DecSmallHoard(*person);
	}
	else if (value == 4) {
		person = new DecMerchantHoard(*person);
	}
	else if (value == 6) {
		person = new DecDragonHoard(*person);
	}
	p->updateChar(person);
}

// move enemies
void Floor::enemyAction() {
	checkDHoards();
	for(int i = 0 ; i < 5 ; i++) {
		rooms[i]->moveEnemys();
	}
	if (action == "") {
		action = "Monsters have suddenly gone still. I guess it's your move? \n";
	}
}


// create player and stairs and place on board
void Floor::spawnPlayerAndStairs(string race) {
	int x = rand() % 5;
	rooms[x]->placePlayer(race);
	int y = rand() % 5;
	while (y == x) {
		y = rand() % 5;
	}
	rooms[y]->placeStairs();
}

// create and array of Enemies and place on board
void Floor::spawnEnemys() {
	int numEn = 20 - DHoards.size();
	Character * enemies[numEn];
	for (int i = 0 ; i < numEn ; i++) {
		int x = rand() % 18;
		if(x <= 3) {
			enemies[i] = new Werewolf;
		}
		else if (x <= 6) {
			enemies[i] = new Vampire;
		}
		else if (x <= 11) {
			enemies[i] = new Goblin;
		}
		else if (x <= 13) {
			enemies[i] = new Troll;
		}
		else if (x <= 15) {
			enemies[i] = new Phoenix;
		}
		else {
			enemies[i] = new Merchant;
		}
	}
	for (int i = 0 ; i < numEn ; i++) {
		int x = rand() % 5;
		rooms[x]->placeEnemy(enemies[i]);
	}
}

// create an array of items and then place on board
void Floor::spawnItems() {
	Item * things[20];
	for (int i = 10 ; i < 20 ; i++) {
		int x = rand() % 6;
		if (x == 0) {
			things[i] = new WoundAtk;
		}
		else if (x == 1) {
			things[i] = new BoostAtk;
		}
		else if (x == 2) {
			things[i] = new PoisonHP;
		}
		else if (x == 3) {
			things[i] = new RestoreHP;
		}
		else if (x == 4) {
			things[i] = new WoundDef;
		}
		else {
			things[i] = new BoostDef;
		}
	}
	for (int i = 0 ; i < 10 ; i++) {
		int x = rand() % 8;
		if (x <= 4) {
			things[i] = new Normal;
		}
		else if (x <= 6) {
			things[i] = new SmallHoard;
		}
		else {
			things[i] = new DragonHoard;
		}
	}
	for (int i = 0 ; i < 20 ; i++) {
		int x = rand() % 5;
		rooms[x]->placeItem(things[i]);
	}
}

// print the floor to the screen
void Floor::printFloor() {
	for (int i = 0 ; i < numRow ; i++) {
		for (int j = 0 ; j < numCol ; j++) {
			cout << c[i][j]->whatsHere();
		}
		cout << endl;
	}
}

// print the Player's current info to the screen
void Floor::printInfo() {
	Character * you = getPlayer();
	cout << "Race: " << you->getRace() << " Gold: " << you->getGold();
	cout << setw(57) << right << "Floor " << level << endl;
	cout << "HP: " << you->getHP() << endl;
	cout << "Atk: " << you->getAtk() << endl;
	cout << "Def: " << you->getDef() << endl;
	cout << "Action: " << action;
}

// check all the DragonHoards to see if Player is near by and make Dragon's Hostile
void Floor::checkDHoards() {
	action  = "";
	for(vector<Cell*>::iterator i = DHoards.begin() ; i != DHoards.end() ; i++) {
		if ((*i)->isNeighbour(p)) {
			if ((*i)->getItem()->getDragon()->whatsHere() == "D") {
				action += (*i)->getItem()->guardMe();
				action += "\n";
			}
		}
	}
}


// move the player one tile in the given direction. If there is gold pick it up.
// if action == a, attack in that direction, if action == u, use potion in that direction
// returns true if the player reaches the stairs
bool Floor::playerTurn(string direction, string acttion) {
	int row = p->getRow();
	int col = p->getCol();
	string type;
	Character *tempc;
	Item * tempi;
	if (direction == "no") {
		row = row - 1;
	}
	else if (direction == "so") {
		row = row + 1;
	}
	else if (direction == "ea") {
		col = col + 1;
	}
	else if (direction == "we") {
		col = col - 1;
	}
	else if (direction == "ne") {
		row = row - 1;
		col = col + 1;
	}
	else if (direction == "nw") {
		row = row - 1;
		col = col - 1;
	}
	else if (direction == "se") {
		row = row + 1;
		col = col + 1;
	}
	else if (direction == "sw") {
		row = row + 1;
		col = col - 1;
	}
	string here = c[row][col]->whatsHere();
	if (here == "P" || here == "G") {
		type = c[row][col]->getItem()->getType();
	}
	if (acttion == "m") {
		bool takeIt = false;
		bool emptyIt = false;
		int prevCham = p->getChamNum();
		// check if it's a free space
		if (here == "." || here == "+" || here == "#") {
			if (here == ".") {
				takeIt = true;
			}
			if (prevCham > 0) {
				emptyIt = true;
			}
			// place character in new cell
			c[row][col]->updateChar(p->getChar());
			// remove character from old cell
			p->updateChar(NULL);
			if (emptyIt) {
				rooms[prevCham - 1]->makeEmpty(p);
			}
			// change player pointer to new cell
			p = c[row][col];
			if (takeIt) {
				rooms[p->getChamNum() - 1]->makeTaken(p);
			}
			if (direction == "no") {
				action = "You moved " + direction + "rth one step. ";
			}
			else if (direction == "so") {
				action = "You moved " + direction + "uth one step. ";
			}

			else if ( direction == "we" || direction == "ea") {
				action = "You moved " + direction + "st one step. ";
			}
			else if ( direction == "ne") {
				action = "You moved northeast one step. ";
			}
			else if (direction  == "nw") {
				action = "You moved northwest one step. ";	
			}
			else if (direction == "se") {
				action = "You moved southeast one step. ";
			}	
			else {
				action = "You moved southwest one step. ";
			}
			action += c[row][col]->checkSurroundings();	
			// add whats new around you
			action += "\n";
			return false;
		}
		// check if it's a staircase
		else if (here == "\\") {
			action = "You found the stairs!";
			action += "\n";
			return true;
		}
		else if(here == "G") {
			if (type == "Dragon Hoard") {
				if (c[row][col]->getItem()->getDragon()->whatsHere() != "D") {
					// wrap player in gold
					c[row][col]->getItem()->Consume();
					for (vector<Cell*>::iterator i = DHoards.begin() ; i != DHoards.end() ; i ++ ) {
						if ((*i) == c[row][col]) {
							DHoards.erase(i);
							break;
						}
					}
					tempi = c[row][col]->getItem();
					c[row][col]->updateItem(NULL);
					delete tempi;
					// place character in new cell
					c[row][col]->updateChar(p->getChar());
					// remove character from old cell
					p->updateChar(NULL);
					rooms[p->getChamNum() - 1]->makeEmpty(p); 
					// change player pointer to new cell
					p = c[row][col]; 
					action = "You picked up a " + type + "!";
				} 
				else {
					if (c[row][col]->getItem()->getDragon()->whatsHere() == "D") {
						action = "You must slay the Dragon first";
					}
				}
			}
			else {
				if(type != "Merchant Hoard") {
					normalGoldCount++;
				}
				// wrap player in gold
				c[row][col]->getItem()->Consume();
				tempi = c[row][col]->getItem();
				c[row][col]->updateItem(NULL);
				delete tempi;
				// place character in new cell
				c[row][col]->updateChar(p->getChar());
				// remove character from old cell
				p->updateChar(NULL);
				if (p->getChamNum() >=1) {
					rooms[p->getChamNum() - 1]->makeEmpty(p);
				}
				// change player pointer to new cell
				p = c[row][col];
				action = "You picked up a " + type + "!";
			}
			action += "\n";
			return false;
		}
		else if (here == "|" || here == "-") {
			action = "You walk into a wall! Good thing your head seems fairly empty.";
			action += "\n";
		}
		else if (here == "P") {
			action  = "You must walk around the potion or drink it.";
			action += "\n";
		}
		else {
			action  = "If you want to quit the game that badly, you can use the command q...";
			action += "\n";
		}
		return false;
	}
	else if (acttion == "u") {
		// use potion
		if (here == "P") {
			c[row][col]->getItem()->Consume();
			action  = "You drink ";
			action += type;
			action += "!";
			if (type == "an Unknown potion") {
				action += " Turns out it was ";
				type = c[row][col]->getItem()->getType();
				action += type;
				action += "!";
				if (getPlayer()->getRace() == "Elf") {
					if (type == "a WoundDef potion") {
						action += " However you are an Elf, so it boosts your Defence.";
					}
					else if (type == "a WoundAtk potion") {
						action += " However you are an Elf, so it boosts your Attack.";
					}
					else if (type == "a PoisonHP potion") {
						action += " However you are an Elf, so it restores your HP.";
					}
				}
			}
			tempi = c[row][col]->getItem();
			c[row][col]->updateItem(NULL);
			delete tempi;
			rooms[c[row][col]->getChamNum() - 1]->makeEmpty(c[row][col]);

		}
		else {
			action = "There is no potion there, silly!";
		}
		action += "\n";
		return false;
	}
	else if (acttion == "a") {
		if(here == "W" || here == "V" || here == "T" || here == "D" || here == "M" || here == "X" || here == "N") {
			action = c[row][col]->getChar()->defend(*(p->getChar()));
			if (here == "M") { c[row][col]->getChar()->setAnger(); }
			if (c[row][col]->getChar()->getHP() == 0) {
				if (here == "M") {
					action += " Slain Merchant drops merchanthoard!";
					tempi = new MerchantHoard;
					c[row][col]->updateItem(tempi);
					tempc = c[row][col]->getChar();
					delete tempc;
					c[row][col]->updateChar(NULL);

				}
				else if (here == "D") {
					action += " You can now pick up the dragonhoard!";
					tempc = c[row][col]->getChar();
					delete tempc;
					c[row][col]->updateChar(NULL);
					rooms[c[row][col]->getChamNum() - 1]->makeEmpty(c[row][col]);
				}
				else {
					normalGoldCount++;
					wrapPlayer(1);
					action += " Slain enemy drops some gold!";
					tempc = c[row][col]->getChar();
					delete tempc;
					c[row][col]->updateChar(NULL);
					rooms[c[row][col]->getChamNum() - 1]->makeEmpty(c[row][col]);
				}
			}
			action += "\n";
		}
		else if(here == "G") {
			action = "You can't attack gold.";
		}
		else if (here == "P") {
			action = "You are supposed to drink potions, not attack them.";
		}
		else if (here == "." || here == "+" || here == "#") {
			action = "You swat ridiculously at the air in front of you!";
		}
		else if (here == "|" || here == "-") {
			action = "You punch the wall, ouch!";
		}
		action += "\n";
		return false;
	}
	return false;
}
