#ifndef GRIMWALL_CROSSBOWMANSPAWNCALLBACK_H
#define GRIMWALL_CROSSBOWMANSPAWNCALLBACK_H

#include "../KeypressCallback.h"
#include "../../Domain/Units/Troups/TroupManager.h"

#include <iostream>

class CrossbowmanSpawnCallback : public KeypressCallback{
public:
    CrossbowmanSpawnCallback(IGame* game);
    virtual void execute() override;
};


#endif
