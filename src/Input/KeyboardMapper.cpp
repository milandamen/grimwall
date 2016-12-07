#include "KeyboardMapper.h"
#include "Callbacks/MoveCallback.h"
#include "Callbacks/UseAbilityCallback.h"

KeyboardMapper::KeyboardMapper(IGame* game)
{
    EngineFacade::engine()->registerCallback("ESCAPE", new QuitCallback(game));
    EngineFacade::engine()->registerCallback("ALT+CTRL+5", new QuitCallback(game));

    EngineFacade::engine()->registerCallback("W", new MoveCallback(game, "UP"));
    EngineFacade::engine()->registerCallback("S", new MoveCallback(game, "DOWN"));
    EngineFacade::engine()->registerCallback("A", new MoveCallback(game, "LEFT"));
    EngineFacade::engine()->registerCallback("D", new MoveCallback(game, "RIGHT"));

    EngineFacade::engine()->registerCallback("RIGHT", new MoveCameraCallback(game, "RIGHT"));
    EngineFacade::engine()->registerCallback("LEFT", new MoveCameraCallback(game, "LEFT"));
    EngineFacade::engine()->registerCallback("DOWN", new MoveCameraCallback(game, "DOWN"));
    EngineFacade::engine()->registerCallback("UP", new MoveCameraCallback(game, "UP"));
    EngineFacade::engine()->registerCallback("=", new ZoomCameraCallback(game, "PLUS"));
    EngineFacade::engine()->registerCallback("-", new ZoomCameraCallback(game, "MINUS"));

    EngineFacade::engine()->registerCallback("1", new UseAbilityCallback(game, 1));
    EngineFacade::engine()->registerCallback("2", new UseAbilityCallback(game, 2));
    EngineFacade::engine()->registerCallback("3", new UseAbilityCallback(game, 3));
    EngineFacade::engine()->registerCallback("4", new UseAbilityCallback(game, 4));
}