#ifndef KEYBOARD_MAPPER_H
#define KEYBOARD_MAPPER_H

#include "../Domain/EngineFacade.h"
#include "Callbacks/QuitCallback.h"
#include "Callbacks/ZoomCameraCallback.h"
#include "Callbacks/TroupSpawnCallback.h"
#include "Callbacks/UseAbilityCallback.h"
#include "Callbacks/AttackCallback.h"
#include "../Domain/IGame.h"

class KeyboardMapper
{
public:
    KeyboardMapper(IGame* game);
};

#endif