#include "FIFECamera.h"

FIFECamera::FIFECamera(FIFE::Map *map, FIFE::EventManager* eventManager, FIFE::TimeManager* timeManager)
    : map{map}, eventManager{eventManager}, timeManager{timeManager} {
    
    zoomIncrement = 0.95;
    maxZoom = 4;
    minZoom = 0.25;
}

FIFECamera::~FIFECamera()
{
    delete this->cameraScroller;
    // No need to delete the rest as they will be deleted on Engine Destroy()
}

void FIFECamera::initView() {
    if(this->map){
        // get the main camera for this map
        this->mainCamera = map->getCamera("main");

        if (this->mainCamera)
        {
            this->mainCamera->setEnabled(true);

            // get the renderer associated with viewing objects on the map
            FIFE::RendererBase* renderer = this->mainCamera->getRenderer("InstanceRenderer");

            if (renderer)
            {
                // activate all layers associated with the renderer
                // for this map, this must be done to see anything
                renderer->activateAllLayers(this->map);
            }
        }
        this->cameraScroller = new FIFECameraScroller(this->mainCamera, this->eventManager, this->timeManager);
    }

}

FIFE::Camera* FIFECamera::camera() const {
    return this->mainCamera;
}

void FIFECamera::zoomIn() {
    if (this->mainCamera)
    {
        // calculate the zoom in level
        double zoom = this->mainCamera->getZoom() / this->zoomIncrement;

        if (zoom <= this->maxZoom)
        {
            this->mainCamera->setZoom(zoom);
        }
    }
}

void FIFECamera::unregisterEvent() {
    this->cameraScroller->unregisterEvent();
}

void FIFECamera::zoomOut(){
    if (this->mainCamera)
    {
        // calculate the zoom out level
        double zoom = mainCamera->getZoom() * this->zoomIncrement;

        if (zoom >= this->minZoom)
        {
            this->mainCamera->setZoom(zoom);
        }
    }
}

void FIFECamera::updateLocation(int x, int y) {
    this->cameraScroller->updateLocation(x,y);
}
