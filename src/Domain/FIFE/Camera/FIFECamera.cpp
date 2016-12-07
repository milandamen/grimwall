#include "FIFECamera.h"

FIFECamera::FIFECamera(FIFE::Map *map, FIFE::EventManager* eventManager, FIFE::TimeManager* timeManager)
: eventManager{eventManager}, timeManager{timeManager}, map{map}{
    zoomIncrement = 0.95;
    maxZoom = 4;
    minZoom = 0.25;
}

void FIFECamera::initView() {
    if(map){
        // get the main camera for this map
        mainCamera = map->getCamera("main");

        if (mainCamera)
        {
            // attach the controller to the camera
//             m_viewController->AttachCamera(mainCamera);
//             m_viewController->EnableCamera(true);
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

FIFE::Location* FIFECamera::getExact(int screenX, int screenY) {
    FIFE::ScreenPoint point = FIFE::ScreenPoint(screenX, screenY);

    FIFE::ExactModelCoordinate coord = map->getLayer("layer1")->getCellGrid()
            ->toMapCoordinates(mainCamera->toMapCoordinates(point));

    FIFE::Location* loc = new FIFE::Location(map->getLayer("layer1"));
    loc->setExactLayerCoordinates(coord);

    FIFE::CellSelectionRenderer::getInstance(mainCamera)->selectLocation(loc);

    return loc;
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

void FIFECamera::updateLocation(std::string location) {
    cameraScroller->updateLocation(location);
}
