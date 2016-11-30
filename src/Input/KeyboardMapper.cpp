#include "KeyboardMapper.h"
#include "Callbacks/MoveCallback.h"

KeyboardMapper::KeyboardMapper(IGame* game)
{
    // SYSTEM
    EngineFacade::engine()->registerCallback("ESCAPE", new QuitCallback(game));
    EngineFacade::engine()->registerCallback("ALT+CTRL+5", new QuitCallback(game));

    // HERO
    EngineFacade::engine()->registerCallback("W", new MoveCallback(game, "UP"));
    EngineFacade::engine()->registerCallback("S", new MoveCallback(game, "DOWN"));
    EngineFacade::engine()->registerCallback("A", new MoveCallback(game, "LEFT"));
    EngineFacade::engine()->registerCallback("D", new MoveCallback(game, "RIGHT"));

    // CAMERA
    EngineFacade::engine()->registerCallback("RIGHT", new MoveCameraCallback(game, "RIGHT"));
    EngineFacade::engine()->registerCallback("LEFT", new MoveCameraCallback(game, "LEFT"));
    EngineFacade::engine()->registerCallback("DOWN", new MoveCameraCallback(game, "DOWN"));
    EngineFacade::engine()->registerCallback("UP", new MoveCameraCallback(game, "UP"));
    EngineFacade::engine()->registerCallback("=", new ZoomCameraCallback(game, "PLUS"));
    EngineFacade::engine()->registerCallback("-", new ZoomCameraCallback(game, "MINUS"));

    // TROUPS
    EngineFacade::engine()->registerCallback("-", new TroupSpawnCallback(game, "1"));
}