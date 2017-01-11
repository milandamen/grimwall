#ifndef ISAVEGAME_STRATEGY_H
#define ISAVEGAME_STRATEGY_H

#include <iostream>

#include "SaveGame.h"

class ISaveGameStrategy
{
public:
    virtual ~ISaveGameStrategy() {}
    virtual void save(SaveGame* saveGame) = 0;
    virtual SaveGame* load(std::string file) = 0;
};

#endif
