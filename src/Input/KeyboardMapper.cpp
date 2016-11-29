#include "KeyboardMapper.h"

KeyboardMapper::KeyboardMapper(IGame* game)
{
    EngineFacade::engine()->registerCallback("ESCAPE", new QuitCallback(game));
    EngineFacade::engine()->registerCallback("RIGHT", new MoveCameraCallback(game, "RIGHT"));
    EngineFacade::engine()->registerCallback("LEFT", new MoveCameraCallback(game, "LEFT"));
    EngineFacade::engine()->registerCallback("DOWN", new MoveCameraCallback(game, "DOWN"));
    EngineFacade::engine()->registerCallback("UP", new MoveCameraCallback(game, "UP"));
    EngineFacade::engine()->registerCallback("=", new ZoomCameraCallback(game, "PLUS"));
    EngineFacade::engine()->registerCallback("-", new ZoomCameraCallback(game, "MINUS"));
    EngineFacade::engine()->registerCallback("W+A+S+D", new QuitCallback(game));
}