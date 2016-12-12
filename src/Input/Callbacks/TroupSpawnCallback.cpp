#include "TroupSpawnCallback.h"
TroupSpawnCallback::TroupSpawnCallback(IGame* game, std::string value) : KeypressCallback(game, 0), value{value}
{

}

void TroupSpawnCallback::execute()
{
    if(value == "1"){

        EngineFacade::engine()->createInstance(
                "standardTroup",
                "standardTroup",
                this->game->getHero()->getX() + 1,
                this->game->getHero()->getY()
        );
        EngineFacade::engine()->createInstance(
                "standardTroup",
                "standardTroup",
                this->game->getHero()->getX() - 1,
                this->game->getHero()->getY()
        );
        EngineFacade::engine()->createInstance(
                "standardTroup",
                "standardTroup",
                this->game->getHero()->getX(),
                this->game->getHero()->getY() + 1
        );
        EngineFacade::engine()->createInstance(
                "standardTroup",
                "standardTroup",
                this->game->getHero()->getX(),
                this->game->getHero()->getY() - 1
        );

    }
}