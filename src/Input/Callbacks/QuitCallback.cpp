#include "QuitCallback.h"

QuitCallback::QuitCallback(IGame* game) : KeypressCallback(game)
{
    
}

void QuitCallback::execute()
{
    game->quit();
}

