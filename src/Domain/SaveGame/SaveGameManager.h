#ifndef SAVEGAME_MANAGER_H
#define SAVEGAME_MANAGER_H

#include "ISaveGameManager.h"
#include "ISaveGameStrategy.h"
#include "TextSaveGameStrategy.h"

class SaveGameManager : public ISaveGameManager
{
private:
    ISaveGameStrategy* strategy {nullptr};
public:
    SaveGameManager(std::string strategy);
    virtual SaveGame* create(std::string file) override;
    virtual void save(SaveGame* saveGame) override;
    virtual SaveGame* load(std::string file) override;
    virtual void setStrategy(std::string strategy) override;
};

#endif
