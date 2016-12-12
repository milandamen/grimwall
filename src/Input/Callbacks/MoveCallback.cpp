#include "MoveCallback.h"

MoveCallback::MoveCallback(IGame* game, std::string direction)
    : KeypressCallback(game, 1), direction{direction}
{
    
}

void MoveCallback::execute() {
    EngineFacade::engine()->move(game->getHero()->getName(), x, y);
}

