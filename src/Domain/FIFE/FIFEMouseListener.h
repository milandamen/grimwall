#ifndef FIFE_MOUSE_LISTENER_H
#define FIFE_MOUSE_LISTENER_H

#include "eventchannel/mouse/ec_imouselistener.h"
#include "eventchannel/mouse/ec_mouseevent.h"
#include "model/structures/layer.h"
#include "model/metamodel/grids/cellgrid.h"


#include <string>
#include <unordered_map>
#include <iostream>

#include "../../Input/MouseCallback.h"
#include "../Units/IUnit.h"
//#include "../EngineFacade.h"
#include "../IGame.h"
#include "Camera/FIFECamera.h"



class FIFEMouseListener : public FIFE::IMouseListener
{
private:
    IGame* game;
    FIFECamera* camera;

    std::unordered_map<std::string, MouseCallback*> callbackMap;

    int dragX;
    int dragY;

    FIFE::MouseEvent::MouseEventType prevEventType;
    FIFE::Instance* instance;

public:
    FIFEMouseListener(IGame* game, FIFECamera* camera);

    virtual ~FIFEMouseListener();

    void registerCallback(std::string click, MouseCallback* callback);

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
    virtual void SetPreviousMouseEvent(FIFE::MouseEvent::MouseEventType type);
    virtual void SetController(FIFE::Instance* instance);


    void setPlayer(IUnit* unit);


};


#endif
