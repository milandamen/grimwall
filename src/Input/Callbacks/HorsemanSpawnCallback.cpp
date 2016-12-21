#include "HorsemanSpawnCallback.h"
HorsemanSpawnCallback::HorsemanSpawnCallback(IGame* game, std::string value) : KeypressCallback(game, 0), value{value}
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