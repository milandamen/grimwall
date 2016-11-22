#ifndef MOUSE_CALLBACK_H
#define MOUSE_CALLBACK_H

#include "ICallback.h"
#include "../Domain/IGame.h"

class MouseCallback : public ICallback
{
protected:
    IGame* game {nullptr};
    IMouseEvent* event {nullptr};
    
    MouseCallback(IGame* game);
public:
    void execute(IMouseEvent* event);
};

#endif