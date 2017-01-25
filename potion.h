#ifndef __POTION_H__
#define __POTION_H__

#include <string>
#include "item.h"

class Potion: public Item {
	std::string type;	// type of potion
	public:
	// ctor
	Potion(std::string type);
	//dtor
	virtual ~Potion()=0;
	// wrap player on board using type
	void callwrapper();
	// used in subclasses to consume
	virtual void Consume()=0;
};

#endif
