#include "MoveCameraCallback.h"

MoveCameraCallback::MoveCameraCallback(IGame* game, std::string direction) : KeypressCallback(game), direction{direction}
{

}

void MoveCameraCallback::execute()
{

    if(direction == "UP"){
        EngineFacade::engine()->updateLocation(2000, 2000);
    }
    else if(direction == "DOWN"){
        EngineFacade::engine()->updateLocation(0, -1);
    }
    else if(direction == "RIGHT"){
        EngineFacade::engine()->updateLocation(+1, 0);
    }
    else if(direction == "LEFT"){
        EngineFacade::engine()->updateLocation(-1, 0);
    }
}