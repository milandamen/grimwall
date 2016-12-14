

#ifndef GRIMWALL_TROUPSPAWNCALLBACK_H
#define GRIMWALL_TROUPSPAWNCALLBACK_H

#include "../KeypressCallback.h"
#include "../../Domain/Units/Troups/TroupManager.h"

#include <iostream>

class TroupSpawnCallback : public KeypressCallback{
private:
    std::string value;
public:
    TroupSpawnCallback(IGame* game, std::string value);
    virtual void execute() override;
};


#endif //GRIMWALL_TROUPSPAWNCALLBACK_H
