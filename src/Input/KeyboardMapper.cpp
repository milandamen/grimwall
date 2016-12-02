#include "KeyboardMapper.h"

KeyboardMapper::KeyboardMapper(IGame* game)
{
    EngineFacade::engine()->registerCallback("ESCAPE", new QuitCallback(game));
    
    // Camera
    EngineFacade::engine()->registerCallback("UP", new MoveCameraCallback(game, 1, "UP"));
    EngineFacade::engine()->registerCallback("RIGHT", new MoveCameraCallback(game, 1, "RIGHT"));
    EngineFacade::engine()->registerCallback("DOWN", new MoveCameraCallback(game, 1, "DOWN"));
    EngineFacade::engine()->registerCallback("LEFT", new MoveCameraCallback(game, 1, "LEFT"));
    EngineFacade::engine()->registerCallback("UP+RIGHT", new MoveCameraCallback(game, 1, "UPRIGHT"));
    EngineFacade::engine()->registerCallback("RIGHT+DOWN", new MoveCameraCallback(game, 1, "RIGHTDOWN"));
    EngineFacade::engine()->registerCallback("DOWN+LEFT", new MoveCameraCallback(game, 1, "DOWNLEFT"));
    EngineFacade::engine()->registerCallback("LEFT+UP", new MoveCameraCallback(game, 1, "LEFTUP"));
    EngineFacade::engine()->registerCallback("=", new ZoomCameraCallback(game, 5, "PLUS"));
    EngineFacade::engine()->registerCallback("-", new ZoomCameraCallback(game, 5, "MINUS"));

    // Hero
    EngineFacade::engine()->registerCallback("W", new MoveCallback(game, 1, "UP"));
    EngineFacade::engine()->registerCallback("D", new MoveCallback(game, 1, "RIGHT"));
    EngineFacade::engine()->registerCallback("S", new MoveCallback(game, 1, "DOWN"));
    EngineFacade::engine()->registerCallback("A", new MoveCallback(game, 1, "LEFT"));
    EngineFacade::engine()->registerCallback("W+D", new MoveCallback(game, 1, "UPRIGHT"));
    EngineFacade::engine()->registerCallback("D+S", new MoveCallback(game, 1, "RIGHTDOWN"));
    EngineFacade::engine()->registerCallback("S+A", new MoveCallback(game, 1, "DOWNLEFT"));
    EngineFacade::engine()->registerCallback("W+A", new MoveCallback(game, 1, "LEFTUP"));
}