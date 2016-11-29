#ifndef IGAME_H
#define IGAME_H

#include "Units/Heroes/AHero.h"

class IGame
{
public:
    virtual AHero* getHero() = 0;
    virtual void quit() = 0;
};

#endif