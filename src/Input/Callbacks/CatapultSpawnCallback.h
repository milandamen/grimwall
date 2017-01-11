#ifndef GRIMWALL_CATAPULTSPAWNCALLBACK_H
#define GRIMWALL_CATAPULTSPAWNCALLBACK_H

#include "../KeypressCallback.h"
#include "../../Domain/Units/Troups/TroupManager.h"

#include <iostream>

class CatapultSpawnCallback : public KeypressCallback{
public:
    CatapultSpawnCallback(IGame* game);
    virtual void execute() override;
};


#endif
