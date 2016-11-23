#include "KeyboardMapper.h"
#include "Callbacks/MoveCallback.h"

KeyboardMapper::KeyboardMapper(IGame* game)
{
    EngineFacade::engine()->registerCallback("ESCAPE", new QuitCallback(game));
    EngineFacade::engine()->registerCallback("ALT+CTRL+5", new QuitCallback(game));

    EngineFacade::engine()->registerCallback("W", new MoveCallback(game, "up"));
    EngineFacade::engine()->registerCallback("S", new MoveCallback(game, "down"));
    EngineFacade::engine()->registerCallback("A", new MoveCallback(game, "left"));
    EngineFacade::engine()->registerCallback("D", new MoveCallback(game, "right"));
}