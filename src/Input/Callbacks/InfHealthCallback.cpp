
#include "InfHealthCallback.h"

InfHealthCallback::InfHealthCallback(IGame *game)
    : KeypressCallback(game, 0)
{}

void InfHealthCallback::execute() {
    if (!shouldExecute()) { return; }

    game->getHero()->setInvincible(true);
}
