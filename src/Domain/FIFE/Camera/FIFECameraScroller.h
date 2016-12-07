#ifndef GRIMWALL_FIFECAMERASCROLLER_H
#define GRIMWALL_FIFECAMERASCROLLER_H


#include "util/base/fife_stdint.h"
#include "util/time/timeevent.h"
#include "eventchannel/command/ec_icommandlistener.h"
#include "eventchannel/sdl/ec_isdleventlistener.h"
#include "view/camera.h"
#include <util/time/timemanager.h>
#include <eventchannel/eventmanager.h>

class FIFECameraScroller : public FIFE::TimeEvent, public FIFE::ISdlEventListener{
public:
    FIFECameraScroller(FIFE::Camera* camera, FIFE::EventManager* eventManager, FIFE::TimeManager* timeManager);
    ~FIFECameraScroller();

    void updateLocation(int x, int y);
    void unregisterEvent();
private:
    void evaluateLocation();
    void updateEvent(uint32_t time);
    bool onSdlEvent(SDL_Event& evt);
private:
    FIFE::Camera* mainCamera;
    FIFE::EventManager* eventManager;
    FIFE::TimeManager* timeManager;
    FIFE::ScreenPoint scrollCoords;

    const int ScrollAmount;
    const float ScrollActivationPercent;

    int cursorX;
    int cursorY;
    int scrollAreaTop;
    int scrollAreaBottom;
    int scrollAreaRight;
    int scrollAreaLeft;
    bool shouldScroll;
    bool eventRegistered;
};


#endif //GRIMWALL_FIFECAMERASCROLLER_H
