#ifndef IGAME_H
#define IGAME_H

#include "Units/Heroes/AHero.h"
#include "Units/UnitManager.hpp"
#include "Units/Towers/ATower.h"
#include "SaveGame/ISaveGameManager.h"

class IGame
{
public:
    virtual UnitManager<AHero>* getHero() = 0;
    virtual void quit() = 0;
    virtual std::vector<UnitManager<ATower>*>* getTowers() = 0;
    virtual void letTowersAttack() = 0;
    virtual ISaveGameManager* getSaveGameManager() = 0;
    virtual void setSaveGameManager(ISaveGameManager* saveGameManager) = 0;
};

#endif