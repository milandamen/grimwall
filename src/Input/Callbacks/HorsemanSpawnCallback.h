#ifndef GRIMWALL_HORSEMANSPAWNCALLBACK_H
#define GRIMWALL_HORSEMANSPAWNCALLBACK_H

#include "../KeypressCallback.h"
#include "../../Domain/Units/Troups/TroupManager.h"

#include <iostream>

class HorsemanSpawnCallback : public KeypressCallback{
public:
    HorsemanSpawnCallback(IGame* game);
    virtual void execute() override;
};


#endif
