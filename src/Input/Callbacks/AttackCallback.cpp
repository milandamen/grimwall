

#include "AttackCallback.h"
#include "../../Domain/UnitFactory.h"
#include "../../Domain/EngineFacade.h"

AttackCallback::AttackCallback(IGame *game)
    : KeypressCallback(game, 0)
{}

void AttackCallback::execute() {
    if (!this->shouldExecute())
        return;

    updateLocation(game->getHero(), "Dralas");

    double x = game->getHero()->getX();
    double y = game->getHero()->getY();
    double reach = game->getHero()->getReach();
    int power = game->getHero()->getPower();

    std::vector<UnitManager<ATower>*> towers = game->getTowers();
    UnitManager<ATower>* tower;
    for (int t = 0; t < towers.size(); ++t) {
        tower = towers[t];

        double xDiff = std::abs(tower->getX() - x);
        double yDiff = std::abs(tower->getY() - y);

        if (xDiff < reach && yDiff < reach) {
            tower->receiveDamage(power);

            if (tower->getHitPoints() <= 0) {
                if (EngineFacade::engine()->instanceExists(tower->getBase()->getId(), "towerLayer")) {
                    EngineFacade::engine()->deleteInstance(tower->getBase()->getId(), "towerLayer");
                }
                game->removeTower(t);
            }
        }
    }
}
