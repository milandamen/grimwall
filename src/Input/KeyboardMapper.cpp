#include "KeyboardMapper.h"

<<<<<<< HEAD
#include "Callbacks/MoveCallback.h"
#include "Callbacks/TroupSpawnCallback.h"
=======
>>>>>>> master
#include "Callbacks/UseAbilityCallback.h"
#include "Callbacks/AttackCallback.h"

KeyboardMapper::KeyboardMapper(IGame* game)
{
    // SYSTEM
    EngineFacade::engine()->registerCallback("ESCAPE", new QuitCallback(game));
    
    // Camera
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

    // TROUPS
    EngineFacade::engine()->registerCallback("5", new TroupSpawnCallback(game, "1"));
    
    // Abilities
    EngineFacade::engine()->registerCallback("SPACE", new AttackCallback(game));
    EngineFacade::engine()->registerCallback("1", new UseAbilityCallback(game, 0));
    EngineFacade::engine()->registerCallback("2", new UseAbilityCallback(game, 1));
    EngineFacade::engine()->registerCallback("3", new UseAbilityCallback(game, 2));
    EngineFacade::engine()->registerCallback("4", new UseAbilityCallback(game, 3));

    // Hero
    EngineFacade::engine()->registerCallback("W", new MoveCallback(game, "UP"));
    EngineFacade::engine()->registerCallback("D", new MoveCallback(game, "RIGHT"));
    EngineFacade::engine()->registerCallback("S", new MoveCallback(game, "DOWN"));
    EngineFacade::engine()->registerCallback("A", new MoveCallback(game, "LEFT"));
    EngineFacade::engine()->registerCallback("W+D", new MoveCallback(game, "UPRIGHT"));
    EngineFacade::engine()->registerCallback("D+S", new MoveCallback(game, "RIGHTDOWN"));
    EngineFacade::engine()->registerCallback("S+A", new MoveCallback(game, "DOWNLEFT"));
    EngineFacade::engine()->registerCallback("W+A", new MoveCallback(game, "LEFTUP"));
}