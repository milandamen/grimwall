#include "LongbowmanSpawnCallback.h"
LongbowmanSpawnCallback::LongbowmanSpawnCallback(IGame* game, std::string value) : KeypressCallback(game, 0), value{value}
{

}

void LongbowmanSpawnCallback::execute()
{
    game->getTroupManager()->createTroup(
            "longbowman",
            this->game->getHero()->getX() + 1,
            this->game->getHero()->getY()
    );

    game->getTroupManager()->createTroup(
            "longbowman",
            this->game->getHero()->getX() - 1,
            this->game->getHero()->getY()
    );
    game->getTroupManager()->createTroup(
            "longbowman",
            this->game->getHero()->getX(),
            this->game->getHero()->getY() + 1
    );
    game->getTroupManager()->createTroup(
            "longbowman",
            this->game->getHero()->getX(),
            this->game->getHero()->getY() - 1
    );
}