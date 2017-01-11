#ifndef ISAVEGAME_MANAGER_H
#define ISAVEGAME_MANAGER_H

#include "SaveGame.h"

class SaveGame;

class ISaveGameManager
{
public:
    virtual ~ISaveGameManager() {}
    virtual SaveGame* create(std::string file) = 0;
    virtual void save(SaveGame* saveGame) = 0;
    virtual SaveGame* load(std::string file) = 0;
    virtual void setStrategy(std::string strategy) = 0;
};

#endif
