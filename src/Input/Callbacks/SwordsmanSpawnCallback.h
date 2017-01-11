#ifndef GRIMWALL_SWORDSMANSPAWNCALLBACK_H
#define GRIMWALL_SWORDSMANSPAWNCALLBACK_H

#include "../KeypressCallback.h"
#include "../../Domain/Units/Troups/TroupManager.h"

#include <iostream>

class SwordsmanSpawnCallback : public KeypressCallback{
private:
    std::string value;
public:
    SwordsmanSpawnCallback(IGame* game);
    virtual void execute() override;
};


#endif //GRIMWALL_SWORDSMANSPAWNCALLBACK_H
