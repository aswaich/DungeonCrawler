#ifndef __CELL_H__
#define __CELL_H__

#include <string>
#include <vector>

class Character;
class Item;

const int maxNeighbours = 8;

class Cell {
	protected:
	int r, c;	// represent the row and column that cell is in
	int numNeighbours;	// the number of neighbours the cell has
	Cell *neighbours[maxNeighbours];	// pointers to the neighbours
	// the chamber that the cell is located in, 0 if not in a chamber
	int chamberNum;
	public:
	// ctor
	Cell(int r, int c, int chamNum);
	//dtor is pure virtual
	virtual ~Cell();
	// adds nei as a neighbour to the cell and increments numNeighbours
	void addNeighbour(Cell * nei);
	// returns a string represnting the specific cell on the board
	virtual std::string whatsHere()=0;

	// update Item field
	virtual void updateItem(Item *);
	// update Character field
	virtual void updateChar(Character *);
	// update the type field
	virtual void updateType(std::string s);

	// checks neighbours and returns a string explaining what's around
	std::string checkSurroundings();
	// get the chamber number
	int getChamNum();
	// get the row coordinate
	int getRow();
	// get the column coordinate 
	int getCol();
	// checks if the given cell is a neighbour of the current cell
	bool isNeighbour(Cell * n);
	// returns a pointer to the Character that is on the cell or NULL if there is none
	virtual Character * getChar()=0;
	// returns a pointer to the item in the cell or NULL
	virtual Item * getItem()=0;
	// returns a vector of all the cells neighbours
	std::vector<Cell *> getNeighbours();

};

#endif
