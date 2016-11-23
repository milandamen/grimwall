//
// Created by joost on 11/23/16.
//

#ifndef GRIMWALL_FIFECAMERA_H
#define GRIMWALL_FIFECAMERA_H


#include <view/camera.h>
#include "model/structures/map.h"

#include "FIFECamera.h"

class FIFECamera{
public:
    FIFECamera(FIFE::Map* map);
    void initView();
    void zoomOut();
    void zoomIn();
private:
    FIFE::Map* map {nullptr};
    FIFE::Camera* mainCamera {nullptr};

    double zoomIncrement;
    double maxZoom;
    double minZoom;
};


#endif //GRIMWALL_FIFECAMERA_H
