#include "EngineFacade.h"

IEngineFacade* EngineFacade::_engine {nullptr};
std::string EngineFacade::currentEngineName {};

IEngineFacade* EngineFacade::engine()
{
    return _engine;
}

void EngineFacade::setEngine(std::string engine, IGame* game)
{
    if (engine == "FIFE" && currentEngineName != engine)
    {
        destroy();
        _engine = new FIFEFacade(game);
    }
}

void EngineFacade::setEngine(IEngineFacade* engine)
{
    if (_engine != nullptr)
    {
        if (_engine == engine) { return; }
        
        destroy();
    }
    
    _engine = engine;
    currentEngineName = "CUSTOM";
}

void EngineFacade::destroy()
{
    delete _engine;
    _engine = nullptr;
}
