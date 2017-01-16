#include "InvisibleCallback.h"

InvisibleCallback::InvisibleCallback(IGame *game)
        : KeypressCallback(game, 0)
{}

void InvisibleCallback::execute() {
    if (!shouldExecute()) { return; }

    game->getHero()->setInvisible(true);

}
