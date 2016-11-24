

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
    ZoomCameraCallback(IGame* game, std::string value);
    virtual void execute() override;
};


#endif //GRIMWALL_ZOOMCAMERACALLBACK_H
