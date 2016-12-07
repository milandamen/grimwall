

#include "UseAbilityCallback.h"

UseAbilityCallback::UseAbilityCallback(IGame *game, int ability)
    : KeypressCallback(game), ability{ability}
{}

void UseAbilityCallback::execute() {
    std::cout << this->game->getHero()->getPower() << std::endl;
    this->game->getHero()->getBase()->executeAbility(this->ability-1);
    std::cout << this->game->getHero()->getPower() << std::endl;
}