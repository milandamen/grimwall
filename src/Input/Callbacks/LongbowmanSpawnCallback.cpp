#include "LongbowmanSpawnCallback.h"
LongbowmanSpawnCallback::LongbowmanSpawnCallback(IGame* game) : KeypressCallback(game, 0)
{

}

void LongbowmanSpawnCallback::execute()
{
    game->getTroupManager()->createLongbowman(
            "longbowman",
            this->game->getHero()->getX() + 1,
            this->game->getHero()->getY()
    );

    game->getTroupManager()->createLongbowman(
            "longbowman",
            this->game->getHero()->getX() - 1,
            this->game->getHero()->getY()
    );
    game->getTroupManager()->createLongbowman(
            "longbowman",
            this->game->getHero()->getX(),
            this->game->getHero()->getY() + 1
    );
    game->getTroupManager()->createLongbowman(
            "longbowman",
            this->game->getHero()->getX(),
            this->game->getHero()->getY() - 1
    );
}