#ifndef MOUSE_CALLBACK_H
#define MOUSE_CALLBACK_H


#include "ICallback.h"
#include "IMouseEvent.h"
#include "../Domain/IGame.h"


class MouseCallback : public ICallback
{
protected:
    IGame* game {nullptr};
    IMouseEvent* event {nullptr};
    
    MouseCallback(IGame* game);
public:
    virtual void execute(IMouseEvent* event);
    virtual ~MouseCallback();
};

#endif