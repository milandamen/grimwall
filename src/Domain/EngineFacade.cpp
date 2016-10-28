
#include "EngineFacade.h"

IEngineFacade* EngineFacade::_engine {nullptr};
std::string EngineFacade::currentEngineName {};

IEngineFacade* EngineFacade::engine()
{
    return _engine;
}

void EngineFacade::setEngine(std::string engine)
{
    if (engine == "FIFE" && currentEngineName != engine)
    {
        destroy();
//        _engine = new FIFEFacade();
    }
}

void EngineFacade::destroy()
{
    delete _engine;
    _engine = nullptr;
}
