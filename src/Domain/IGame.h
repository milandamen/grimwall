#ifndef IGAME_H
#define IGAME_H

#include "Units/Heroes/AHero.h"
#include "Units/Troups/ATroup.h"
#include "Units/UnitManager.hpp"
#include "Units/Towers/ATower.h"
#include "Units/Troups/TroupManager.h"
#include "SaveGame/ISaveGameManager.h"
#include "ILevel.h"

class TroupManager;

class IGame{
public:
    virtual void init() = 0;
    virtual void loadLevel(std::string levelName) = 0;
    virtual ILevel* getCurrentLevel() = 0;
    virtual void setMap(std::string path) = 0;
    virtual bool isPaused() = 0;
    virtual void setPaused(bool paused) = 0;
    virtual void setHero(AHero* hero) = 0;
    virtual void setUI(std::string name) = 0;
    virtual int getCurrentScore() = 0;
    virtual UnitManager<AHero>* getHero() = 0;
    virtual TroupManager* getTroupManager() = 0;
    virtual void quit() = 0;
    virtual std::vector<UnitManager<ATower>*>* getTowers() = 0;
    virtual ISaveGameManager* getSaveGameManager() = 0;
    virtual void setSaveGameManager(ISaveGameManager* saveGameManager) = 0;
    virtual void saveGame() = 0;
    virtual void loadGame(std::string fileName) = 0;
    virtual void setSpeedHack(bool enabled) = 0;
};

#endif