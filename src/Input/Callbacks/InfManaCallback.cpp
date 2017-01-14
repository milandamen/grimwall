
#include "InfManaCallback.h"

InfManaCallback::InfManaCallback(IGame *game)
    : KeypressCallback(game, 0)
{}

void InfManaCallback::execute() {
    if (!shouldExecute()) { return; }

    game->getHero()->getBase()->setInfMana(true);
}
