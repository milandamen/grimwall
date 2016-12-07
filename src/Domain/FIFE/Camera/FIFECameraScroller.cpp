#include "FIFECameraScroller.h"

FIFECameraScroller::FIFECameraScroller(FIFE::Camera *camera, FIFE::EventManager *eventManager, FIFE::TimeManager *timeManager)
        : mainCamera(camera), eventManager(eventManager), timeManager(timeManager), ScrollAmount(10),
          ScrollActivationPercent(0.02f), eventRegistered(false)
{
    // set the period for timing event in ms
    setPeriod(20);
}

FIFECameraScroller::~FIFECameraScroller()
{
    unregisterEvent();
}


void FIFECameraScroller::evaluateLocation(std::string location)
{
    scrollCoords = mainCamera->toScreenCoordinates(mainCamera->getLocationRef().getMapCoordinates());

    shouldScroll = false;

    if(location == "UP"){
        scrollCoords[1] -= ScrollAmount;

        shouldScroll = true;
    }
    if(location == "DOWN"){
        scrollCoords[1] += ScrollAmount;

        shouldScroll = true;
    }
    if(location == "RIGHT"){
        scrollCoords[0] += ScrollAmount;

        shouldScroll = true;
    }
    if(location == "LEFT"){
        scrollCoords[0] -= ScrollAmount;

        shouldScroll = true;
    }
}


void FIFECameraScroller::updateLocation(std::string location)
{
    // test whether we should be scrolling
    evaluateLocation(location);

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
    if (evt.type == SDL_WINDOWEVENT && evt.window.event == SDL_KEYUP)
    {
        unregisterEvent();
        return true;
    }

    return false;
}