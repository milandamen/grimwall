#include "CatapultSpawnCallback.h"
CatapultSpawnCallback::CatapultSpawnCallback(IGame* game) : KeypressCallback(game, 120)
{

}

void CatapultSpawnCallback::execute()
{
    if(game->getHero()->getBase()->summon()){
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
}