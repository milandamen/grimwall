#include "CrossbowmanSpawnCallback.h"
CrossbowmanSpawnCallback::CrossbowmanSpawnCallback(IGame* game, std::string value) : KeypressCallback(game, 0), value{value}
{

}

void CrossbowmanSpawnCallback::execute()
{
    game->getTroupManager()->createCrossbowman(
            "crossbowman",
            this->game->getHero()->getX() + 1,
            this->game->getHero()->getY()
    );

    game->getTroupManager()->createCrossbowman(
            "crossbowman",
            this->game->getHero()->getX() - 1,
            this->game->getHero()->getY()
    );
    game->getTroupManager()->createCrossbowman(
            "crossbowman",
            this->game->getHero()->getX(),
            this->game->getHero()->getY() + 1
    );
    game->getTroupManager()->createCrossbowman(
            "crossbowman",
            this->game->getHero()->getX(),
            this->game->getHero()->getY() - 1
    );
}