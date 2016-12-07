#ifndef GRIMWALL_MOVECAMERACALLBACK_H
#define GRIMWALL_MOVECAMERACALLBACK_H

#include "../KeypressCallback.h"
#include "../../Domain/IGame.h"
#include "../../Domain/EngineFacade.h"

#include <iostream>


class MoveCameraCallback : public KeypressCallback {
private:
    std::string direction;
public:
    /**
     * Create a MoveCameraCallback object
     * 
     * @param game An instance of IGame that the callback can execute methods on
     * @param firePerNFrames Callback fires every N frames or only once if set to 0. Fires while keys are held.
     * @param direction Move the camera in a certain direction (UP, DOWN, LEFT, RIGHT, UPRIGHT, RIGHTDOWN, DOWNLEFT, LEFTUP)
     */
    MoveCameraCallback(IGame* game, int firePerNFrames, std::string direction);
    virtual void execute() override;
};


#endif //GRIMWALL_MOVECAMERACALLBACK_H
