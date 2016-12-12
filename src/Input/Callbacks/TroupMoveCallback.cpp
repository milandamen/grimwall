#include "TroupMoveCallback.h"
TroupMoveCallback::TroupMoveCallback(IGame* game, std::string value) : KeypressCallback(game, 0), value{value}
{

}

void TroupMoveCallback::execute()
{
    // game->getTroupManager()->moveTroups(x, y);
}