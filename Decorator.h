#ifndef __DECORATOR_H__
#define __DECORATOR_H__

#include "character.h"

class CharDecorator : public Character {
  protected:
    Character &playerChar;

  public:
    // default ctor and dtor implementations

    CharDecorator(Character &playerChar);
    virtual ~CharDecorator();
};

#endif
