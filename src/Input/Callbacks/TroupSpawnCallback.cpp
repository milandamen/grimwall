#include "TroupSpawnCallback.h"
TroupSpawnCallback::TroupSpawnCallback(IGame* game, std::string value) : KeypressCallback(game, 0), value{value}
{

}

void TroupSpawnCallback::execute()
{
    game->getTroupManager()->createTroup(
            "basicTroup",
            this->game->getHero()->getX() + 1,
            this->game->getHero()->getY()
    );

    game->getTroupManager()->createTroup(
            "basicTroup",
            this->game->getHero()->getX() - 1,
            this->game->getHero()->getY()
    );
    game->getTroupManager()->createTroup(
            "basicTroup",
            this->game->getHero()->getX(),
            this->game->getHero()->getY() + 1
    );
    game->getTroupManager()->createTroup(
            "basicTroup",
            this->game->getHero()->getX(),
            this->game->getHero()->getY() - 1
    );
}