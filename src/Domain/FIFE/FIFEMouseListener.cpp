#include "FIFEMouseListener.h"

using namespace std;
using namespace FIFE;

FIFEMouseListener::FIFEMouseListener(IGame *game, FIFECamera* camera) : game{game}, camera{camera}, prevEventType(FIFE::MouseEvent::UNKNOWN_EVENT),
instance(0), dragX(0), dragY(0){}

FIFEMouseListener::~FIFEMouseListener() {
    for (auto &&item : callbackMap) {
        delete item.second;
    }
    callbackMap.clear();
}

void FIFEMouseListener::mouseEntered(FIFE::MouseEvent& evt) {
    SetPreviousMouseEvent(evt.getType());
//    cout<< "Mouse Entered \n";
}
void FIFEMouseListener::mouseExited(FIFE::MouseEvent& evt) {
    SetPreviousMouseEvent(evt.getType());
//    cout<< "Mouse Exited \n";
}
void FIFEMouseListener::mousePressed(FIFE::MouseEvent& evt) {
    if (evt.getButton() == FIFE::MouseEvent::LEFT)
    {
        // save mouse position
        dragX = evt.getX();
        dragY = evt.getY();
    }

    SetPreviousMouseEvent(evt.getType());
}

void FIFEMouseListener::setCamera(FIFECamera* camera) {
    this->camera = camera;
}

void FIFEMouseListener::mouseReleased(FIFE::MouseEvent& evt) {
    // only activate the move action if the mouse was pressed and released without dragging
    if (/*instance &&*/ evt.getButton() == FIFE::MouseEvent::LEFT && prevEventType != FIFE::MouseEvent::DRAGGED)
    {
        // move controller to clicked spot
        //FIFE::Location destination(instance->getLocation());
        FIFE::ScreenPoint screenPoint(evt.getX(), evt.getY());
        FIFE::ExactModelCoordinate mapCoords = camera->Camera()->toMapCoordinates(screenPoint, false);
        mapCoords.z = 0.0;
        //destination.setMapCoordinates(mapCoords);
        std::cout << "X: " << mapCoords.x << ", Y:" << mapCoords.y << std::endl;
        //instance->move("walk", destination, instance->getTotalTimeMultiplier());
    }

    SetPreviousMouseEvent(evt.getType());
//    cout << "Mouse Released \n";
}
void FIFEMouseListener::mouseClicked(FIFE::MouseEvent& evt) {
    SetPreviousMouseEvent(evt.getType());
//    cout<< "Mouse clicked \n";
}
void FIFEMouseListener::mouseWheelMovedUp(FIFE::MouseEvent& evt) {
    // zoom in
    camera->zoomIn();

    // save mouse position
    dragX = evt.getX();
    dragY = evt.getY();

    SetPreviousMouseEvent(evt.getType());
//    cout<< "Scrolled up\n";
}
void FIFEMouseListener::mouseWheelMovedDown(FIFE::MouseEvent& evt) {
    // zoom out
    camera->zoomOut();

    SetPreviousMouseEvent(evt.getType());
//    cout<< "Scrolled down \n";
}
void FIFEMouseListener::mouseMoved(FIFE::MouseEvent& evt) {
    camera->updateLocation(evt.getX(), evt.getY());

    SetPreviousMouseEvent(evt.getType());
//    cout<< "Mouse has moved \n";
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
        FIFE::ScreenPoint delta(dragX - currX, dragY - currY);

        // get the current camera location
        FIFE::ScreenPoint cameraScreenCoords = camera->Camera()->toScreenCoordinates(camera->Camera()->getLocationRef().getMapCoordinates());
        cameraScreenCoords += delta;

        // set the new coordinates
        FIFE::Location camLocation(camera->Camera()->getLocationRef());
        FIFE::ExactModelCoordinate mapCoords = camera->Camera()->toMapCoordinates(cameraScreenCoords, false);
        mapCoords.z = 0.0;
        camLocation.setMapCoordinates(mapCoords);
        camera->Camera()->setLocation(camLocation);

        // update last saved x,y values for dragging
        dragX = currX;
        dragY = currY;
    }

    // make sure to save that the last event was drag
    // this is important to get around the drag & click problem
    SetPreviousMouseEvent(evt.getType());
//    cout<< "Dragging the mouse \n";
}

void FIFEMouseListener::SetPreviousMouseEvent(FIFE::MouseEvent::MouseEventType type)
{
    prevEventType = type;
}

