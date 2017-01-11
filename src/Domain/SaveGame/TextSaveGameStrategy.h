#ifndef TEXT_SAVEGAME_STRATEGY_H
#define TEXT_SAVEGAME_STRATEGY_H

#include <iostream>
#include <fstream>
#include <ios>
#include <vector>

#include "ISaveGameStrategy.h"
#include "ISaveGameManager.h"

class TextSaveGameStrategy : public ISaveGameStrategy
{
private:
    ISaveGameManager* saveGameManager {nullptr};
public:
    TextSaveGameStrategy(ISaveGameManager* saveGameManager);
    virtual void save(SaveGame* saveGame) override;
    virtual SaveGame* load(std::string file) override;
};

#endif
