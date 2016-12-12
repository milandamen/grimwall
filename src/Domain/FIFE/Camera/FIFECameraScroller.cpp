#include "FIFECameraScroller.h"

FIFECameraScroller::FIFECameraScroller(FIFE::Camera *camera, FIFE::EventManager *eventManager, FIFE::TimeManager *timeManager)
        : mainCamera(camera), eventManager(eventManager), timeManager(timeManager), scrollAmount(10),
          scrollActivationPercent(0.1f), eventRegistered(false)
{
    // set the period for timing event in ms
    setPeriod(20);

    if (mainCamera)
    {
        // get the viewport for the camera
        const FIFE::Rect& viewport = mainCamera->getViewPort();

        // calculate borders to activate automatic scrolling
        scrollAreaTop = static_cast<int>(viewport.h - (viewport.h*scrollActivationPercent));
        scrollAreaBottom = static_cast<int>(viewport.y + (viewport.h*scrollActivationPercent));
        scrollAreaRight = static_cast<int>(viewport.w - (viewport.w*scrollActivationPercent));
        scrollAreaLeft = static_cast<int>(viewport.x + (viewport.w*scrollActivationPercent));
    }
}

FIFECameraScroller::~FIFECameraScroller()
{
    unregisterEvent();
}


void FIFECameraScroller::evaluateLocation()
{
    scrollCoords = mainCamera->toScreenCoordinates(mainCamera->getLocationRef().getMapCoordinates());

    //get the viewport for the camera so we can fetch the screen size
    const FIFE::Rect& viewport = mainCamera->getViewPort();

    shouldScroll = false;

    // Check if the mouse is out of screen
    if(cursorX < 1 || cursorX > viewport.right() - 2
            || cursorY < 1 || cursorY > viewport.bottom() - 2) {
        shouldScroll = false;
    }
    else{
        // check left
        if (cursorX <= scrollAreaLeft)
        {
            // Camera shouldn't move when out of screen

            // modify x value
            scrollCoords[0] -= scrollAmount;

            shouldScroll = true;

        }

        // check right
        else if (cursorX >= scrollAreaRight)
        {
            // modify x value
            scrollCoords[0] += scrollAmount;

            shouldScroll = true;
        }

        // check top
        if (cursorY >= scrollAreaTop)
        {
            // modify y value
            scrollCoords[1] += scrollAmount;

            shouldScroll = true;
        }
            // check bottom
        else if (cursorY <= scrollAreaBottom)
        {
            // modify y value
            scrollCoords[1] -= scrollAmount;

            shouldScroll = true;
        }
    }
}


void FIFECameraScroller::updateLocation(int x, int y)
{
    cursorX = x;
    cursorY = y;

    // test whether we should be scrolling
    evaluateLocation();

    if (shouldScroll && !eventRegistered)
    {
        // register ourself as an event handler to make
        // sure we can capture if our window looses focus
        // so we don't keep scrolling in that case
        timeManager->registerEvent(this);
        eventManager->addSdlEventListener(this);
        eventRegistered = true;

        // call our internal updater here to kick it off
        updateEvent(-1);
    }
}

void FIFECameraScroller::unregisterEvent()
{
    if (eventRegistered)
    {
        timeManager->unregisterEvent(this);
        eventManager->removeSdlEventListener(this);
        eventRegistered = false;
    }
}

void FIFECameraScroller::updateEvent(uint32_t time)
{

    if (shouldScroll)
    {
        FIFE::Location camLocation(mainCamera->getLocationRef());
        FIFE::ExactModelCoordinate mapCoords = mainCamera->toMapCoordinates(scrollCoords, false);
        mapCoords.z = 0.0;
        camLocation.setMapCoordinates(mapCoords);

        mainCamera->setLocation(camLocation);

        //stop from moving the camera
        unregisterEvent();
    }
    else
    {
        unregisterEvent();
    }
}

bool FIFECameraScroller::onSdlEvent(SDL_Event& evt)
{
    // if it is a mouse focus event and we have lost focus
    // then we need to unregister for events until
    // we have regained focus
    if (evt.type == SDL_WINDOWEVENT && evt.window.event == SDL_WINDOWEVENT_LEAVE)
    {

        unregisterEvent();
        return true;
    }

    return false;
}