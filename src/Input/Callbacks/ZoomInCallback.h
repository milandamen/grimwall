#include "../MouseCallback.h"

class ZoomInCallback : public MouseCallback
{
public:
    ZoomInCallback(IGame* game);
    virtual void execute() override;
};