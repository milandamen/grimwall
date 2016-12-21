#ifndef GRIMWALL_HORSEMANSPAWNCALLBACK_H
#define GRIMWALL_HORSEMANSPAWNCALLBACK_H

#include "../KeypressCallback.h"
#include "../../Domain/Units/Troups/TroupManager.h"

#include <iostream>

class HorsemanSpawnCallback : public KeypressCallback{
private:
    std::string value;
public:
    HorsemanSpawnCallback(IGame* game, std::string value);
    virtual void execute() override;
};


#endif
