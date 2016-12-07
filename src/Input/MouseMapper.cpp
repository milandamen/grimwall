#include "MouseMapper.h"

MouseMapper::MouseMapper(IGame* game)
{
    // Hero
    EngineFacade::engine()->registerCallback("W", new MoveCallback(game, 1));
}