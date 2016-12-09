#include "FIFEMouseListener.h"
#include "../EngineFacade.h"

using namespace std;
using namespace FIFE;

FIFEMouseListener::FIFEMouseListener(IGame *game, FIFECamera* camera) : game{game}, camera{camera}, dragX{0}, dragY{0}, prevEventType{FIFE::MouseEvent::UNKNOWN_EVENT},
instance{0}{}

FIFEMouseListener::~FIFEMouseListener() {
    for (auto&& item : callbackMap) {
        delete item.second;
    }
    callbackMap.clear();
}

void FIFEMouseListener::mouseEntered(FIFE::MouseEvent& evt) {
    setPreviousMouseEvent(evt.getType());
}
void FIFEMouseListener::mouseExited(FIFE::MouseEvent& evt) {
    setPreviousMouseEvent(evt.getType());
}
void FIFEMouseListener::mousePressed(FIFE::MouseEvent& evt) {
    if (evt.getButton() == FIFE::MouseEvent::LEFT)
    {
        // save mouse position
        dragX = evt.getX();
        dragY = evt.getY();
    }

    setPreviousMouseEvent(evt.getType());
}

void FIFEMouseListener::setCamera(FIFECamera* camera) {
    this->camera = camera;
}

void FIFEMouseListener::mouseReleased(FIFE::MouseEvent& evt) {
    // only activate the move action if the mouse was pressed and released without dragging
    if (evt.getButton() == FIFE::MouseEvent::LEFT && prevEventType != FIFE::MouseEvent::DRAGGED)
    {
        EngineFacade::engine()->move("Dralas", evt.getX(), evt.getY());
    }

    setPreviousMouseEvent(evt.getType());
}
void FIFEMouseListener::mouseClicked(FIFE::MouseEvent& evt) {
    setPreviousMouseEvent(evt.getType());
}
void FIFEMouseListener::mouseWheelMovedUp(FIFE::MouseEvent& evt) {
    // zoom in
    camera->zoomIn();

    // save mouse position
    dragX = evt.getX();
    dragY = evt.getY();

    setPreviousMouseEvent(evt.getType());
}
void FIFEMouseListener::mouseWheelMovedDown(FIFE::MouseEvent& evt) {
    // zoom out
    camera->zoomOut();

    setPreviousMouseEvent(evt.getType());
}
void FIFEMouseListener::mouseMoved(FIFE::MouseEvent& evt) {
    camera->updateLocation(evt.getX(), evt.getY());

    setPreviousMouseEvent(evt.getType());
}
void FIFEMouseListener::mouseDragged(FIFE::MouseEvent& evt) {
    if (evt.getButton() == FIFE::MouseEvent::LEFT)
    {
        // unregister the auto-scrolling event
        // we are now scrolling manually and do not
        // want both trying to do it at the same time
        camera->unregisterEvent();

        // get the screen coordinates of the mouse
        int currX = evt.getX();
        int currY = evt.getY();

        // get the mouse delta for camera movement
        FIFE::ScreenPoint delta {dragX - currX, dragY - currY};

        // get the current camera location
        FIFE::ScreenPoint cameraScreenCoords = camera->camera()->toScreenCoordinates(camera->camera()->getLocationRef().getMapCoordinates());
        cameraScreenCoords += delta;

        // set the new coordinates
        FIFE::Location camLocation(camera->camera()->getLocationRef());
        FIFE::ExactModelCoordinate mapCoords = camera->camera()->toMapCoordinates(cameraScreenCoords, false);
        mapCoords.z = 0.0;
        camLocation.setMapCoordinates(mapCoords);
        camera->camera()->setLocation(camLocation);

        // update last saved x,y values for dragging
        dragX = currX;
        dragY = currY;
    }

    // make sure to save that the last event was drag
    // this is important to get around the drag & click problem
    setPreviousMouseEvent(evt.getType());
}

void FIFEMouseListener::setPreviousMouseEvent(FIFE::MouseEvent::MouseEventType type)
{
    prevEventType = type;
}

