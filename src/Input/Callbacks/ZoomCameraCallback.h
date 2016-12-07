

#ifndef GRIMWALL_ZOOMCAMERACALLBACK_H
#define GRIMWALL_ZOOMCAMERACALLBACK_H

#include "../KeypressCallback.h"
#include "../../Domain/IGame.h"
#include "../../Domain/EngineFacade.h"

#include <iostream>

class ZoomCameraCallback : public KeypressCallback{
private:
    std::string value;
public:
    /**
     * Create a ZoomCameraCallback object
     * 
     * @param game An instance of IGame that the callback can execute methods on
     * @param firePerNFrames Callback fires every N frames or only once if set to 0. Fires while keys are held.
     * @param value Direction of zooming (PLUS, MINUS)
     */
    ZoomCameraCallback(IGame* game, std::string value);
    virtual void execute() override;
};


#endif //GRIMWALL_ZOOMCAMERACALLBACK_H
