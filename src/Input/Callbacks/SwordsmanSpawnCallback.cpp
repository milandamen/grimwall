#include "SwordsmanSpawnCallback.h"
SwordsmanSpawnCallback::SwordsmanSpawnCallback(IGame* game) : KeypressCallback(game, 0), value{value}
{

}

void SwordsmanSpawnCallback::execute()
{
    game->getTroupManager()->createSwordsman(
            "swordsman",
            this->game->getHero()->getX() + 1,
            this->game->getHero()->getY()
    );

    game->getTroupManager()->createSwordsman(
            "swordsman",
            this->game->getHero()->getX() - 1,
            this->game->getHero()->getY()
    );
    game->getTroupManager()->createSwordsman(
            "swordsman",
            this->game->getHero()->getX(),
            this->game->getHero()->getY() + 1
    );
    game->getTroupManager()->createSwordsman(
            "swordsman",
            this->game->getHero()->getX(),
            this->game->getHero()->getY() - 1
    );
}