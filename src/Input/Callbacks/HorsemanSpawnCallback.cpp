#include "HorsemanSpawnCallback.h"
HorsemanSpawnCallback::HorsemanSpawnCallback(IGame* game) : KeypressCallback(game, 0)
{

}

void HorsemanSpawnCallback::execute()
{
    game->getTroupManager()->createHorseman(
            "horseman",
            this->game->getHero()->getX() + 1,
            this->game->getHero()->getY()
    );

    game->getTroupManager()->createHorseman(
            "horseman",
            this->game->getHero()->getX() - 1,
            this->game->getHero()->getY()
    );
    game->getTroupManager()->createHorseman(
            "horseman",
            this->game->getHero()->getX(),
            this->game->getHero()->getY() + 1
    );
    game->getTroupManager()->createHorseman(
            "horseman",
            this->game->getHero()->getX(),
            this->game->getHero()->getY() - 1
    );
}