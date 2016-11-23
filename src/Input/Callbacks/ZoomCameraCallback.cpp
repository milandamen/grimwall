

#include "ZoomCameraCallback.h"
ZoomCameraCallback::ZoomCameraCallback(IGame* game, std::string value) : KeypressCallback(game), value{value}
{

}

void ZoomCameraCallback::execute()
{
    if(value == "PLUS"){
        EngineFacade::engine()->zoomIn();
    }
    else if(value == "MINUS"){
        EngineFacade::engine()->zoomOut();
    }
}