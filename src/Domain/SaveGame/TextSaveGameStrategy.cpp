#include "TextSaveGameStrategy.h"

TextSaveGameStrategy::TextSaveGameStrategy(ISaveGameManager* saveGameManager) : saveGameManager(saveGameManager)
{

}

void TextSaveGameStrategy::save(SaveGame* saveGame)
{
    std::ofstream fileStream {saveGame->file, std::ios::out | std::ios::trunc};
    if (fileStream.is_open())
    {
        fileStream << saveGame->lastUnlockedLevel << "\n";
        fileStream << saveGame->lastUsedHero << "\n";
        fileStream << saveGame->score << std::endl;
        
        fileStream.close();
    }
    else
    {
        std::cout << "Could not open savegame: " << saveGame->file << std::endl;
    }
}

SaveGame* TextSaveGameStrategy::load(std::string file)
{
    std::ifstream fileStream {file};
    if (!fileStream.is_open())
    {
        std::cout << "Could not open savegame: " << file << std::endl;
        return nullptr;
    }
    
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(fileStream, line))
    {
        if (line != "")
        {
            lines.push_back(line);
        }
    }
    
    if (lines.size() < 2)          // Number of properties SaveGame has
    {
        std::cout << "The savegame you are trying to open is corrupt (lines): " << file << std::endl;
        return nullptr;
    }
    
    SaveGame* saveGame {new SaveGame {saveGameManager}};
    saveGame->file = file;
    
    try
    {
        saveGame->lastUnlockedLevel = lines.at(0);
        
        if (saveGame->lastUnlockedLevel == "level0")
        {
            std::cout << "The savegame you are trying to open is corrupt (level0): " << file << std::endl;
            return nullptr;
        }

        saveGame->score = lines.size() == 3 ? lines.at(2) : "0";
    }
    catch (std::invalid_argument e)
    {
        std::cout << "The savegame you are trying to open is corrupt (level): " << file << std::endl;
        return nullptr;
    }
    
    saveGame->lastUsedHero = lines.at(1);
    
    return saveGame;
}
