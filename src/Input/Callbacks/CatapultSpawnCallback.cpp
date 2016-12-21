#include "CatapultSpawnCallback.h"
CatapultSpawnCallback::CatapultSpawnCallback(IGame* game, std::string value) : KeypressCallback(game, 0), value{value}
{

}

void CatapultSpawnCallback::execute()
{
    game->getTroupManager()->createCatapult(
            "catapult",
            this->game->getHero()->getX() + 1,
            this->game->getHero()->getY()
    );

    game->getTroupManager()->createCatapult(
            "catapult",
            this->game->getHero()->getX() - 1,
            this->game->getHero()->getY()
    );
    game->getTroupManager()->createCatapult(
            "catapult",
            this->game->getHero()->getX(),
            this->game->getHero()->getY() + 1
    );
    game->getTroupManager()->createCatapult(
            "catapult",
            this->game->getHero()->getX(),
            this->game->getHero()->getY() - 1
    );
}