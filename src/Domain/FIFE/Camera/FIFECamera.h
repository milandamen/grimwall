#ifndef GRIMWALL_FIFECAMERA_H
#define GRIMWALL_FIFECAMERA_H

#include <view/camera.h>
#include <eventchannel/mouse/ec_mouseevent.h>
#include <util/time/timemanager.h>
#include <eventchannel/eventmanager.h>
#include "model/structures/map.h"
#include "model/structures/layer.h"
#include "model/metamodel/grids/cellgrid.h"
#include "model/structures/location.h"
#include "view/renderers/cellselectionrenderer.h"

#include "FIFECameraScroller.h"

class FIFECamera{
public:
    FIFECamera(FIFE::Map* map, FIFE::EventManager* eventManager, FIFE::TimeManager* timeManager);
    ~FIFECamera();

    void initView();
    void zoomOut();
    void zoomIn();
    void updateLocation(int x, int y);
    void unregisterEvent();

    FIFE::Camera* Camera() const;
private:
    FIFE::Map* map {nullptr};
    FIFE::Camera* mainCamera {nullptr};
    FIFECameraScroller* cameraScroller {nullptr};
    FIFE::EventManager* eventManager {nullptr};
    FIFE::TimeManager* timeManager {nullptr};

    double zoomIncrement;
    double maxZoom;
    double minZoom;
};

#endif //GRIMWALL_FIFECAMERA_H
