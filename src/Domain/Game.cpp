
#include "Game.h"
#include "EngineFacade.h"

Game::Game()
{
    EngineFacade::setEngine("FIFE");
    
    EngineFacade::destroy();
}
