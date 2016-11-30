#ifndef IGAME_H
#define IGAME_H

#include "Units/Heroes/AHero.h"
#include "Units/UnitManager.h"

class IGame
{
public:
    virtual UnitManager* getHero() = 0;
    virtual void quit() = 0;
};

#endif