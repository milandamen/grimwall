#ifndef KEYPRESS_CALLBACK_H
#define KEYPRESS_CALLBACK_H

#include "ICallback.h"
#include "../Domain/IGame.h"

class KeypressCallback : public ICallback
{
protected:
    IGame* game;
    int firePerNFrames {};
    int currentFrame {};
    int lastExecutedFrame {};
    
    /**
     * Create a KeypressCallback object
     * 
     * @param game An instance of IGame that the callback can execute methods on
     * @param firePerNFrames Callback fires every N frames or only once if set to 0. Fires while keys are held.
     */
    KeypressCallback(IGame* game, int firePerNFrames);
    bool shouldExecute();
public:
    void reset();
};

#endif