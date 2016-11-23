#ifndef FIFE_MOUSE_LISTENER_H
#define FIFE_MOUSE_LISTENER_H

#include "eventchannel/mouse/ec_imouselistener.h"

#include <string>
#include <unordered_map>
#include <iostream>

#include "../../Input/MouseCallback.h"
#include "../Units/IUnit.h"
//#include "../EngineFacade.h"
#include "../IGame.h"




class FIFEMouseListener : public FIFE::IMouseListener
{
private:
    IGame* game;
    std::unordered_map<std::string, MouseCallback*> callbackMap;

    int dragX;
    int dragY;

public:
    FIFEMouseListener(IGame* game);
    virtual ~FIFEMouseListener();

    void registerCallback(std::string click, MouseCallback* callback);

    virtual void mouseEntered(FIFE::MouseEvent& evt);
    virtual void mouseExited(FIFE::MouseEvent& evt);
    virtual void mousePressed(FIFE::MouseEvent& evt);
    virtual void mouseReleased(FIFE::MouseEvent& evt);
    virtual void mouseClicked(FIFE::MouseEvent& evt);
    virtual void mouseWheelMovedUp(FIFE::MouseEvent& evt);
    virtual void mouseWheelMovedDown(FIFE::MouseEvent& evt);
    virtual void mouseMoved(FIFE::MouseEvent& evt);
    virtual void mouseDragged(FIFE::MouseEvent& evt);

    void setPlayer(IUnit* unit);







};


#endif