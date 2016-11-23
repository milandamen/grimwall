#ifndef KEYPRESS_CALLBACK_H
#define KEYPRESS_CALLBACK_H

#include "ICallback.h"
#include "../Domain/IGame.h"

class KeypressCallback : public ICallback
{
protected:
    IGame* game;
    
    KeypressCallback(IGame* game);
};

#endif