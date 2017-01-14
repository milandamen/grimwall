

#include "AttackCallback.h"
#include "../../Domain/UnitFactory.h"
#include "../../Domain/EngineFacade.h"

AttackCallback::AttackCallback(IGame *game)
    : KeypressCallback(game, 0)
{}

void AttackCallback::execute() {
    if (!shouldExecute()) { return; }

    auto hero = game->getHero();

    double x = hero->getX();
    double y = hero->getY();
    double reach = hero->getReach();
    int power = hero->getPower();

    // Commence the attack animation on the unit.
    // TODO: Replace "talk" with a more fitting animation.
    EngineFacade::engine()->setInstanceAction(hero->getName(), "attack");


    std::vector<UnitManager<ATower>*>* towers = game->getTowers();
    UnitManager<ATower>* tower;
    for(std::vector<UnitManager<ATower>*>::iterator it = towers->begin(); it != towers->end();) {
        tower = *it;

        double xDiff = std::abs(tower->getX() - x);
        double yDiff = std::abs(tower->getY() - y);

        if (xDiff < reach && yDiff < reach) {
            tower->receiveDamage(power);

            if (tower->getHitPoints() <= 0) {
                if (EngineFacade::engine()->instanceExists(tower->getBase()->getId(), "towerLayer")) {
                    EngineFacade::engine()->deleteInstance(tower->getBase()->getId(), "towerLayer");
                }

                delete tower;
                towers->erase(it);
            } else {
                ++it;
            }
        } else {
            ++it;
        }
    }
}
