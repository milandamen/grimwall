
#include "Game.h"
#include "EngineFacade.h"

Game::Game()
{
    EngineFacade::setEngine("FIFE");
    EngineFacade::engine()->setRenderBackend("OpenGL");
    
    EngineFacade::engine()->init();
    
    EngineFacade::destroy();
}
