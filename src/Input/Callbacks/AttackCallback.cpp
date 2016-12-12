

#include "AttackCallback.h"

AttackCallback::AttackCallback(IGame *game)
    : KeypressCallback(game, 0)
{}

void AttackCallback::execute() {
    int reach = game->getHero()->getReach();
    int power = game->getHero()->getPower();

    /** TODO:
     * get towers
     * filter towers that in range
     * do damage to tower
    **/
}
