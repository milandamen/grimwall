

#ifndef GRIMWALL_INFMANACALLBACK_H
#define GRIMWALL_INFMANACALLBACK_H

#include "../KeypressCallback.h"

class InfManaCallback : public KeypressCallback {
public:
    InfManaCallback(IGame* game);
    virtual void execute() override;
};


#endif //GRIMWALL_INFMANACALLBACK_H
