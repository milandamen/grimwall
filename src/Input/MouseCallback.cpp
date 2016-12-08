#include "MouseCallback.h"
#include <iostream>

MouseCallback::MouseCallback(IGame* game) : game {game}
{

}

void MouseCallback::execute(IMouseEvent* event)
{
    this->event = event;
    std::cout << "mousecallback execute called";
//    execute();
    delete event;
}
