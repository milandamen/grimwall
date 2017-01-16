

#ifndef GRIMWALL_INFHEALTHCALLBACK_H
#define GRIMWALL_INFHEALTHCALLBACK_H

#include "../KeypressCallback.h"

class InfHealthCallback : public KeypressCallback {
public:
    InfHealthCallback(IGame* game);
    virtual void execute() override;
};


#endif //GRIMWALL_INFHEALTHCALLBACK_H
