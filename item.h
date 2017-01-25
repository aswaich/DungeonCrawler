#ifndef __ITEM_H__
#define __ITEM_H__

#include <string>

class Floor;
class Cell;

class Item {
	protected:
	std::string name;	// represents the symbol on the board
	Floor * board;		// pointer to the board
	public:
	// ctor will get an instance of the floor (board)
	Item(std::string name);
	// dtor
	virtual ~Item();
	// returns a string representing the item on the board
	std::string whatAmI();
	// calls wrapper on person
	virtual void callwrapper()=0;	
	// consumes the item, grabs in the case of gold
	virtual void Consume()=0;
	// returns the specific type of item if it's known
	virtual std::string getType()=0;
	// returns the Dragon pointer
	virtual Cell * getDragon();
	// called when a player is too close to the Hoard to make the Dragon attack
	virtual std::string guardMe();
	// sets smaug
	virtual void setDragon(Cell *);
	// returns true is we know what the type is 
	virtual bool isConsumed();
	// sets consumed to false where needed;
	virtual void vomit();
};

#endif
