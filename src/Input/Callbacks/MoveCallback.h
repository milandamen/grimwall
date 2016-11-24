

#ifndef GRIMWALL_MOVECALLBACK_H
#define GRIMWALL_MOVECALLBACK_H

#include <iostream>
#include "../KeypressCallback.h"

class MoveCallback : public KeypressCallback {
public:
    MoveCallback(IGame* game, std::string direction);
    virtual void execute() override;
private:
    std::string direction;

    double increaser{0.1};

    void up();
    void left();
    void right();
    void down();
};


#endif //GRIMWALL_MOVECALLBACK_H
