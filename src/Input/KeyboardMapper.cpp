#include "KeyboardMapper.h"
<<<<<<< HEAD


=======
>>>>>>> 4c2ec6c7f40c8ea393fefc91ea2d47b8dd7bb449
#include "Callbacks/UseAbilityCallback.h"
#include "Callbacks/AttackCallback.h"

KeyboardMapper::KeyboardMapper(IGame* game)
{
    EngineFacade::engine()->registerCallback("ESCAPE", new QuitCallback(game));
    
    // Camera
    //EngineFacade::engine()->registerCallback("UP", new MoveCameraCallback(game, 1, "UP"));
    //EngineFacade::engine()->registerCallback("RIGHT", new MoveCameraCallback(game, 1, "RIGHT"));
    //EngineFacade::engine()->registerCallback("DOWN", new MoveCameraCallback(game, 1, "DOWN"));
    //EngineFacade::engine()->registerCallback("LEFT", new MoveCameraCallback(game, 1, "LEFT"));
    //EngineFacade::engine()->registerCallback("UP+RIGHT", new MoveCameraCallback(game, 1, "UPRIGHT"));
    //EngineFacade::engine()->registerCallback("RIGHT+DOWN", new MoveCameraCallback(game, 1, "RIGHTDOWN"));
    //EngineFacade::engine()->registerCallback("DOWN+LEFT", new MoveCameraCallback(game, 1, "DOWNLEFT"));
    //EngineFacade::engine()->registerCallback("LEFT+UP", new MoveCameraCallback(game, 1, "LEFTUP"));
    //EngineFacade::engine()->registerCallback("=", new ZoomCameraCallback(game, 5, "PLUS"));
    //EngineFacade::engine()->registerCallback("-", new ZoomCameraCallback(game, 5, "MINUS"));


    EngineFacade::engine()->registerCallback("SPACE", new AttackCallback(game));
    EngineFacade::engine()->registerCallback("1", new UseAbilityCallback(game, 0));
    EngineFacade::engine()->registerCallback("2", new UseAbilityCallback(game, 1));
    EngineFacade::engine()->registerCallback("3", new UseAbilityCallback(game, 2));
    EngineFacade::engine()->registerCallback("4", new UseAbilityCallback(game, 3));

}