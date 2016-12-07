

#ifndef GRIMWALL_USEABILTYCALLBACK_H
#define GRIMWALL_USEABILTYCALLBACK_H


#include "../KeypressCallback.h"

class UseAbilityCallback : public KeypressCallback {
private:
    int ability;
public:
    UseAbilityCallback(IGame* game, int ability);
    virtual void execute() override;
};


#endif //GRIMWALL_USEABILTYCALLBACK_H
