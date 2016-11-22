#ifndef KEYBOARD_MAPPER_H
#define KEYBOARD_MAPPER_H

#include "../Domain/EngineFacade.h"
#include "Callbacks/QuitCallback.h"
#include "../Domain/IGame.h"

class KeyboardMapper
{
public:
    KeyboardMapper(IGame* game);
};

#endif