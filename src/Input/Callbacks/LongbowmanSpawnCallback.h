#ifndef GRIMWALL_LONGBOWMANSPAWNCALLBACK_H
#define GRIMWALL_LONGBOWMANSPAWNCALLBACK_H

#include "../KeypressCallback.h"
#include "../../Domain/Units/Troups/TroupManager.h"

#include <iostream>

class LongbowmanSpawnCallback : public KeypressCallback{
public:
    LongbowmanSpawnCallback(IGame* game);
    virtual void execute() override;
};


#endif
