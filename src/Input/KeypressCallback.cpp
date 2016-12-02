#include "KeypressCallback.h"

KeypressCallback::KeypressCallback(IGame* game, int firePerNFrames) : game (game), firePerNFrames (firePerNFrames)
{

}

bool KeypressCallback::shouldExecute()
{
    currentFrame++;
    
    if (firePerNFrames == 0 && currentFrame == 1)
    {
        lastExecutedFrame++;
        return true;
    }
    
    if (currentFrame - lastExecutedFrame >= firePerNFrames)
    {
        lastExecutedFrame = currentFrame;
        return true;
    }
    
    return false;
}

void KeypressCallback::reset()
{
    currentFrame = 0;
    lastExecutedFrame = 0;
}
