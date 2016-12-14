#include "SaveGameManager.h"

SaveGameManager::SaveGameManager(std::string strategy)
{
    this->setStrategy(strategy);
}

SaveGame* SaveGameManager::create(std::string file)
{
    SaveGame* saveGame {new SaveGame {this}};
    saveGame->file = file;
    save(saveGame);
    return saveGame;
}

void SaveGameManager::save(SaveGame* saveGame)
{
    strategy->save(saveGame);
}

SaveGame* SaveGameManager::load(std::string file)
{
    return strategy->load(file);
}

void SaveGameManager::setStrategy(std::string strategy)
{
    if (strategy == "TEXT")
    {
        if (this->strategy != nullptr) { delete this->strategy; }
        
        this->strategy = new TextSaveGameStrategy {this};
    }
}
