#include "KeyboardMapper.h"
#include "Callbacks/MoveCallback.h"

KeyboardMapper::KeyboardMapper(IGame* game)
{
    EngineFacade::engine()->registerCallback("ESCAPE", new QuitCallback(game));
    EngineFacade::engine()->registerCallback("ALT+CTRL+5", new QuitCallback(game));

    EngineFacade::engine()->registerCallback("W", new MoveCallback(game, "UP"));
    EngineFacade::engine()->registerCallback("S", new MoveCallback(game, "DOWN"));
    EngineFacade::engine()->registerCallback("A", new MoveCallback(game, "LEFT"));
    EngineFacade::engine()->registerCallback("D", new MoveCallback(game, "RIGHT"));
}