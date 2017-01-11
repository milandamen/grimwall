#include "SaveGame.h"

SaveGame::SaveGame(ISaveGameManager* iSaveGameManager) : iSaveGameManager(iSaveGameManager)
{

}

void SaveGame::save()
{
    this->iSaveGameManager->save(this);
}
