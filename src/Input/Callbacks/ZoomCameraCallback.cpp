

#include "ZoomCameraCallback.h"
ZoomCameraCallback::ZoomCameraCallback(IGame* game, std::string value)
        : KeypressCallback(game, 1), value{value}
{

}

void ZoomCameraCallback::execute()
{
    if (!shouldExecute()) { return; }
    
    if(value == "PLUS"){
        EngineFacade::engine()->zoomIn();
    }
    else if(value == "MINUS"){
        EngineFacade::engine()->zoomOut();
    }
}