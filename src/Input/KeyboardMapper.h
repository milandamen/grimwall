#ifndef KEYBOARD_MAPPER_H
#define KEYBOARD_MAPPER_H

#include "../Domain/EngineFacade.h"
#include "Callbacks/QuitCallback.h"
#include "Callbacks/ZoomCameraCallback.h"
#include "Callbacks/SwordsmanSpawnCallback.h"
#include "Callbacks/CrossbowmanSpawnCallback.h"
#include "Callbacks/LongbowmanSpawnCallback.h"
#include "Callbacks/HorsemanSpawnCallback.h"
#include "Callbacks/CatapultSpawnCallback.h"
#include "Callbacks/UseAbilityCallback.h"
#include "Callbacks/AttackCallback.h"
#include "Callbacks/InfHealthCallback.h"
#include "Callbacks/InfManaCallback.h"
#include "Callbacks/InvisibleCallback.h"
#include "../Domain/IGame.h"

class KeyboardMapper
{
public:
    KeyboardMapper(IGame* game);
};

#endif