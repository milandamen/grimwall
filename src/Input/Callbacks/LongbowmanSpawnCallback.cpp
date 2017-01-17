#include "LongbowmanSpawnCallback.h"
LongbowmanSpawnCallback::LongbowmanSpawnCallback(IGame* game) : KeypressCallback(game, 120)
{

}

void LongbowmanSpawnCallback::execute()
{
    if(game->getHero()->getBase()->summon()) {
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
}