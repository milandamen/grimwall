#include "MoveCameraCallback.h"

MoveCameraCallback::MoveCameraCallback(IGame* game, std::string direction) : KeypressCallback(game), direction{direction}
{

}

void MoveCameraCallback::execute()
{
    if(direction == "UP"){
        EngineFacade::engine()->updateLocation(direction);
    }
    else if(direction == "DOWN"){
        EngineFacade::engine()->updateLocation(direction);
    }
    else if(direction == "RIGHT"){
        EngineFacade::engine()->updateLocation(direction);
    }
    else if(direction == "LEFT"){
        EngineFacade::engine()->updateLocation(direction);
    }
}