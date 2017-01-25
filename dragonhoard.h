#ifndef __DRAGON_HOARD_H__
#define __DRAGON_HOARD_H__

#include "treasure.h"

class Cell;

class DragonHoard: public Treasure {
	Cell * smaug;	// Cell containing the Dragon that gaurds the DragonHoard
	public:
	// ctor, creates smaug
	DragonHoard();
	// dtor, must delete smaug
	~DragonHoard();
	// returns the Dragon pointer
	Cell * getDragon();
	// sets smaug
	void setDragon(Cell *);
	// called when a player is too close to the Hoard to make the Dragon attack
	std::string guardMe();
	// return the type
	std::string getType();
};

#endif
