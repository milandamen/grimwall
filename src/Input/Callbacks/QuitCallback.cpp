#include "QuitCallback.h"

QuitCallback::QuitCallback(IGame* game) : KeypressCallback(game, 0)
{
    
}

void QuitCallback::execute()
{
    if (!shouldExecute()) { return; }
    
    game->quit();
}

