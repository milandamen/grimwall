

#include "UseAbilityCallback.h"

UseAbilityCallback::UseAbilityCallback(IGame *game, int ability)
    : KeypressCallback(game, 0), ability{ability}
{}

void UseAbilityCallback::execute() {
    if (!this->shouldExecute())
        return;

    this->game->getHero()->getBase()->executeAbility(this->ability);
}