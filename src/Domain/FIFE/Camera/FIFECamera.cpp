#include "FIFECamera.h"

FIFECamera::FIFECamera(FIFE::Map *map, FIFE::EventManager* eventManager, FIFE::TimeManager* timeManager)
    : map{map}, eventManager{eventManager}, timeManager{timeManager} {
    
    zoomIncrement = 0.95;
    maxZoom = 4;
    minZoom = 0.25;
}

FIFECamera::~FIFECamera()
{
    delete cameraScroller;
    // No need to delete the rest as they will be deleted on Engine Destroy()
}

void FIFECamera::initView() {
    if(map){
        // get the main camera for this map
        mainCamera = map->getCamera("main");

        if (mainCamera)
        {
            // attach the controller to the camera
            mainCamera->setEnabled(true);

            // get the renderer associated with viewing objects on the map
            FIFE::RendererBase* renderer = mainCamera->getRenderer("InstanceRenderer");

            if (renderer)
            {
                // activate all layers associated with the renderer
                // for this map, this must be done to see anything
                renderer->activateAllLayers(map);
            }
        }
        cameraScroller = new FIFECameraScroller(mainCamera, eventManager, timeManager);
    }

}

FIFE::Camera* FIFECamera::Camera() const {
    return mainCamera;
}

void FIFECamera::zoomIn() {
    if (mainCamera)
    {
        // calculate the zoom in level
        double zoom = mainCamera->getZoom() / zoomIncrement;

        if (zoom <= maxZoom)
        {
            mainCamera->setZoom(zoom);
        }
    }
}

void FIFECamera::unregisterEvent() {
    cameraScroller->unregisterEvent();
}

void FIFECamera::zoomOut(){
    if (mainCamera)
    {
        // calculate the zoom out level
        double zoom = mainCamera->getZoom() * zoomIncrement;

        if (zoom >= minZoom)
        {
            mainCamera->setZoom(zoom);
        }
    }
}

void FIFECamera::updateLocation(int x, int y) {
    cameraScroller->updateLocation(x,y);
}
