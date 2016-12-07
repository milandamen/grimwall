#include "MoveCallback.h"

MoveCallback::MoveCallback(IGame* game, int firePerNFrames, double x, double y)
    : KeypressCallback(game, firePerNFrames), x{x}, y{y}
{
    
}

void MoveCallback::execute() {
    EngineFacade::engine()->move("Dralas", x, y);
}

