#include "SwordsmanSpawnCallback.h"
SwordsmanSpawnCallback::SwordsmanSpawnCallback(IGame* game, std::string value) : KeypressCallback(game, 0), value{value}
{

}

void SwordsmanSpawnCallback::execute()
{
    game->getTroupManager()->createTroup(
            "swordsman",
            this->game->getHero()->getX() + 1,
            this->game->getHero()->getY()
    );

    game->getTroupManager()->createTroup(
            "swordsman",
            this->game->getHero()->getX() - 1,
            this->game->getHero()->getY()
    );
    game->getTroupManager()->createTroup(
            "swordsman",
            this->game->getHero()->getX(),
            this->game->getHero()->getY() + 1
    );
    game->getTroupManager()->createTroup(
            "swordsman",
            this->game->getHero()->getX(),
            this->game->getHero()->getY() - 1
    );
}