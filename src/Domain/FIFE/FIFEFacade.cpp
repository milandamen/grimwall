 
#include "FIFEFacade.h"

FIFEFacade::FIFEFacade()
{
    engine = new FIFE::Engine();
}

FIFEFacade::~FIFEFacade()
{
    delete engine;
}

void FIFEFacade::setRenderBackend(std::string engine)
{
    
}

void FIFEFacade::setScreenWidth(int width)
{

}

void FIFEFacade::setScreenHeight(int height)
{

}

void FIFEFacade::setFullScreen(bool fullScreen)
{

}

void FIFEFacade::setWindowTitle(std::__cxx11::string title)
{

}

void FIFEFacade::init()
{

}

void FIFEFacade::loadMap(std::__cxx11::string path)
{

}

void FIFEFacade::render()
{

}
