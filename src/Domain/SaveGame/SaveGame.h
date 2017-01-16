#ifndef SAVEGAME_H
#define SAVEGAME_H

#include <iostream>
#include "ISaveGameManager.h"

class ISaveGameManager;

class SaveGame
{
private:
    ISaveGameManager* iSaveGameManager {nullptr};
public:
    std::string score {""};
    std::string file {""};
    std::string lastUnlockedLevel {"level1"};
    std::string lastUsedHero {"Dralas"};
    
    SaveGame(ISaveGameManager* iSaveGameManager);
    void save();
};

#endif
