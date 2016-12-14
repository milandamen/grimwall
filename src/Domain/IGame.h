#ifndef IGAME_H
#define IGAME_H

#include "Units/Heroes/AHero.h"
#include "Units/Troups/ATroup.h"
#include "Units/UnitManager.hpp"
#include "Units/Towers/ATower.h"
//#include "Units/Troups/TroupManager.h"

class TroupManager;

class IGame{
public:
    virtual UnitManager<AHero>* getHero() = 0;
    virtual TroupManager* getTroupManager() = 0;
    virtual void quit() = 0;
    virtual std::vector<UnitManager<ATower>*> getTowers() = 0;
};

#endif