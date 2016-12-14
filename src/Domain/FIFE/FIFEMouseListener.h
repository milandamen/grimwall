#ifndef FIFE_MOUSE_LISTENER_H
#define FIFE_MOUSE_LISTENER_H

#include "eventchannel/mouse/ec_imouselistener.h"
#include "eventchannel/mouse/ec_mouseevent.h"
#include "model/structures/layer.h"
#include "model/metamodel/grids/cellgrid.h"

#include <string>
#include <unordered_map>
#include <iostream>

#include "../Units/IUnit.h"
//#include "../IGame.h"
#include "Camera/FIFECamera.h"
class IGame;


class FIFEMouseListener : public FIFE::IMouseListener
{
private:
    IGame* game {nullptr};
    FIFECamera* camera {nullptr};

    int dragX;
    int dragY;

    int mousePosX;
    int mousePosY;

    FIFE::MouseEvent::MouseEventType prevEventType;
    FIFE::Instance* instance {nullptr};

    void mouseLeftButtonPressed(FIFE::MouseEvent& evt);

public:
    FIFEMouseListener(IGame* game, FIFECamera* camera);

    virtual ~FIFEMouseListener();


    void setCamera(FIFECamera* camera);

    virtual void mouseEntered(FIFE::MouseEvent& evt);
    virtual void mouseExited(FIFE::MouseEvent& evt);
    virtual void mousePressed(FIFE::MouseEvent& evt);
    virtual void mouseReleased(FIFE::MouseEvent& evt);
    virtual void mouseClicked(FIFE::MouseEvent& evt);
    virtual void mouseWheelMovedUp(FIFE::MouseEvent& evt);
    virtual void mouseWheelMovedDown(FIFE::MouseEvent& evt);
    virtual void mouseMoved(FIFE::MouseEvent& evt);
    virtual void mouseDragged(FIFE::MouseEvent& evt);
    virtual void setPreviousMouseEvent(FIFE::MouseEvent::MouseEventType type);
    virtual void tick();

    void setPlayer(IUnit* unit);
};


#endif
