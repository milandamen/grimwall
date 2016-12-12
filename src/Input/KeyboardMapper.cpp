#include "KeyboardMapper.h"

#include "Callbacks/UseAbilityCallback.h"
#include "Callbacks/AttackCallback.h"

KeyboardMapper::KeyboardMapper(IGame* game)
{
    EngineFacade::engine()->registerCallback("ESCAPE", new QuitCallback(game));
   
    EngineFacade::engine()->registerCallback("UP", new MoveCameraCallback(game, "UP"));
    EngineFacade::engine()->registerCallback("RIGHT", new MoveCameraCallback(game, "RIGHT"));
    EngineFacade::engine()->registerCallback("DOWN", new MoveCameraCallback(game, "DOWN"));
    EngineFacade::engine()->registerCallback("LEFT", new MoveCameraCallback(game, "LEFT"));
    EngineFacade::engine()->registerCallback("UP+RIGHT", new MoveCameraCallback(game, "UPRIGHT"));
    EngineFacade::engine()->registerCallback("RIGHT+DOWN", new MoveCameraCallback(game, "RIGHTDOWN"));
    EngineFacade::engine()->registerCallback("DOWN+LEFT", new MoveCameraCallback(game, "DOWNLEFT"));
    EngineFacade::engine()->registerCallback("LEFT+UP", new MoveCameraCallback(game, "LEFTUP"));
    EngineFacade::engine()->registerCallback("=", new ZoomCameraCallback(game, "PLUS"));
    EngineFacade::engine()->registerCallback("-", new ZoomCameraCallback(game, "MINUS"));

    EngineFacade::engine()->registerCallback("SPACE", new AttackCallback(game));
    EngineFacade::engine()->registerCallback("1", new UseAbilityCallback(game, 0));
    EngineFacade::engine()->registerCallback("2", new UseAbilityCallback(game, 1));
    EngineFacade::engine()->registerCallback("3", new UseAbilityCallback(game, 2));
    EngineFacade::engine()->registerCallback("4", new UseAbilityCallback(game, 3));
}