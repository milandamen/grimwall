#include "MouseCallback.h"
#include <iostream>

MouseCallback::MouseCallback(IGame* game) : game {game}
{

}

void MouseCallback::execute(IMouseEvent* event)
{
    this->event = event;
//    execute();
    delete event;
}
