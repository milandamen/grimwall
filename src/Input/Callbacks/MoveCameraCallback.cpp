#include "MoveCameraCallback.h"

MoveCameraCallback::MoveCameraCallback(IGame* game, std::string direction)
        : KeypressCallback(game, 1), direction{direction}
{

}

void MoveCameraCallback::execute()
{
    if (!shouldExecute()) { return; }
    
//    // You can move in multiple directions at once
//    if (direction.find("UP") != std::string::npos) {
//        EngineFacade::engine()->updateLocation("UP");
//    }
//    if (direction.find("RIGHT") != std::string::npos) {
//        EngineFacade::engine()->updateLocation("RIGHT");
//    }
//    if (direction.find("DOWN") != std::string::npos) {
//        EngineFacade::engine()->updateLocation("DOWN");
//    }
//    if (direction.find("LEFT") != std::string::npos) {
//        EngineFacade::engine()->updateLocation("LEFT");
//    }
}