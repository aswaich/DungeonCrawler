#ifndef __FLOOR_H__
#define __FLOOR_H__

#include <vector>
#include <string>
#include "chamber.h"

class Item;
class Cell;

class Floor {
	Cell *** c;	// 2D array of Cells representing the board
	Cell * p;	// pointer to the cell that our player is contained in
	std::vector <Cell*> DHoards;	// array of pointers to cells with DragonHoards
	// number of rows and columns in the Floor
	int numRow;
	int numCol;
	// represnts what floor we are on
	int level;
	// string holding the action that just happened
	std::string action;
	// array of the Chambers
	Chamber * rooms[5];
	static Floor * instance;	// pointer back to the Floor
	int normalGoldCount;


	// create an array of Enemys then call placeEnemy on each one
	void spawnEnemys();
	// create an array of Items then call placeItem on each one
	void spawnItems();
	// Create the Player and stairs and randomly decide which Chamber they go in
	void spawnPlayerAndStairs(std::string);
	// method to clean up
	static void cleanup();
	// ctor
	Floor();

	public:
	//dtor
	~Floor();
	
	// sets all potions to be unknown
	void clearPotions();
	// set Merchants to be calm
	void calmMerchants();	
	// returns a vector containing the dragonHoards
	std::vector <Cell*> getDHoards();
	// adds a cell to DHoards
	void addDHoard(Cell *);
	// get Player
	Character * getPlayer();
	// set the player
	void setPlayer(Cell *);
	// wrap the player in a potion
	void wrapPlayer(std::string type);
	// wrap the player in gold
	void wrapPlayer(int value);

	// set the action string
	void setAction(std::string);
	// get the action string
	std::string getAction();
	// creates an instance of the Floor or returns one that already exists
	static Floor * getInstance();
	// move the player one tile in the given direction and follow action
	bool playerTurn(std::string direction, std::string action = "m");
	// move enemies
	void enemyAction();
	// check all the DragonHoads to see if a player is too close
	void checkDHoards();
	// creates a board for level l
	void createBoard(int rows, int columns, int l, std::string race, std::string file = "default");
	// print the layour of the floor to the screen
	void printFloor();
	// print all the player info
	void printInfo();
};

#endif
