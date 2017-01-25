#ifndef __CHAMBER_H__
#define __CHAMBER_H__

#include <vector>
#include <string>

class Cell;
class Character;
class Floor;
class Item;

class Chamber {
	std::vector<Cell *> empty;	// array of pointers to cells that are empty
	std::vector<Cell *> taken;	// array of pointers to cells that are occupied
	int freeCells;	// number of Cells that are free
	Floor * theFloor;	// pointer to the floor
	public:
	// ctor that takes in the number of cells the chamber contains
	Chamber();

	// looks for a merchant and if it finds one returns true and calms the merchant
	bool calmMerchant();
	// resets consumed for all potions
	void clearPotion();
	// add a Cell to empty, increases freeCells by 1
	void addEmpty(Cell * c);
	// move a cell from empty to taken
	void makeTaken(Cell * c);
	// move a cell from taken to empty
	void makeEmpty(Cell * c);

	// place Item thing in a random free square
	void placeItem(Item *thing);
	// place Enemy enem in a random free square
	void placeEnemy(Character * enem);
	// place the player in a random free square
	void placePlayer(std::string race);
	// place stairs in a random free square
	void placeStairs();
	// move the enemies (fight if by player or move one random tile)
	void moveEnemys();
};

#endif
