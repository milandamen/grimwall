

#include "ZoomCameraCallback.h"
ZoomCameraCallback::ZoomCameraCallback(IGame* game, int firePerNFrames, std::string value) : KeypressCallback(game, firePerNFrames), value{value}
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