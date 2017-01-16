

#include "AttackCallback.h"
#include "../../Domain/UnitFactory.h"
#include "../../Domain/EngineFacade.h"

AttackCallback::AttackCallback(IGame *game)
    : KeypressCallback(game, 0)
{}

void AttackCallback::execute() {
    if (!shouldExecute()) { return; }

    if (game->getHero()->attack()) {
        double x = game->getHero()->getX();
        double y = game->getHero()->getY();
        double reach = game->getHero()->getReach();
        int power = game->getHero()->getPower();

        // Commence the attack animation on the unit.
        EngineFacade::engine()->setInstanceAction(game->getHero()->getName(), "attack");

        std::vector<UnitManager<ATower> *> *towers = game->getTowers();
        UnitManager<ATower> *tower;
        for (std::vector<UnitManager<ATower> *>::iterator it = towers->begin(); it != towers->end();) {
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
}
