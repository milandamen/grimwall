#ifndef GRIMWALL_FIFECAMERA_H
#define GRIMWALL_FIFECAMERA_H


#include <view/camera.h>
#include <eventchannel/mouse/ec_mouseevent.h>
#include <util/time/timemanager.h>
#include <eventchannel/eventmanager.h>
#include "model/structures/map.h"

#include "FIFECameraScroller.h"

class FIFECamera{
private:
    FIFE::Map* map {nullptr};
    FIFE::Camera* mainCamera {nullptr};
    FIFECameraScroller* cameraScroller {nullptr};
    FIFE::EventManager* eventManager {nullptr};
    FIFE::TimeManager* timeManager {nullptr};

    double zoomIncrement;
    double maxZoom;
    double minZoom;
public:
    FIFECamera(FIFE::Map* map, FIFE::EventManager* eventManager, FIFE::TimeManager* timeManager);
    ~FIFECamera();

    void initView();
    void zoomOut();
    void zoomIn();
    void updateLocation(std::string location);
};


#endif //GRIMWALL_FIFECAMERA_H
