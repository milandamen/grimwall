#ifndef IGAME_H
#define IGAME_H

#include "Units/Heroes/AHero.h"
#include "Units/Troups/ATroup.h"
#include "Units/UnitManager.hpp"
#include "Units/Troups/TroupManager.h"

class IGame
{
public:
    virtual UnitManager<AHero>* getHero() = 0;
    virtual TroupManager* getTroupManager() = 0;
    virtual UnitManager<std::vector<ATroup> >* getTroups() = 0;
    virtual void quit() = 0;
};

#endif