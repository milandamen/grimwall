#ifndef GRIMWALL_CATAPULTSPAWNCALLBACK_H
#define GRIMWALL_CATAPULTSPAWNCALLBACK_H

#include "../KeypressCallback.h"
#include "../../Domain/Units/Troups/TroupManager.h"

#include <iostream>

class CatapultSpawnCallback : public KeypressCallback{
private:
    std::string value;
public:
    CatapultSpawnCallback(IGame* game);
    virtual void execute() override;
};


#endif
