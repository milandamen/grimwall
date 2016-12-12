

#ifndef GRIMWALL_MOVECALLBACK_H
#define GRIMWALL_MOVECALLBACK_H

#include <iostream>
#include "../KeypressCallback.h"
#include "../../Domain/EngineFacade.h"

class MoveCallback : public KeypressCallback {
private:
    double x, y;

public:
    /**
     * Create a MoveCallback object
     * 
     * @param game An instance of IGame that the callback can execute methods on
     * @param firePerNFrames Callback fires every N frames or only once if set to 0. Fires while keys are held.
     * @param direction Move the hero in a certain direction (UP, RIGHT, DOWN, LEFT, UPRIGHT, RIGHTDOWN, DOWNLEFT, LEFTUP)
     */
MoveCallback(IGame* game, int firePerNFrames, double x, double y);
    virtual void execute() override;
};


#endif //GRIMWALL_MOVECALLBACK_H
