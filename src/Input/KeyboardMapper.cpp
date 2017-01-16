#include "KeyboardMapper.h"



KeyboardMapper::KeyboardMapper(IGame* game)
{
    // SYSTEM
    EngineFacade::engine()->registerCallback("ESCAPE", new QuitCallback(game));
    
    EngineFacade::engine()->registerCallback("=", new ZoomCameraCallback(game, "PLUS"));
    EngineFacade::engine()->registerCallback("-", new ZoomCameraCallback(game, "MINUS"));

    // TROUPS
    EngineFacade::engine()->registerCallback("5", new SwordsmanSpawnCallback(game));
    EngineFacade::engine()->registerCallback("6", new CrossbowmanSpawnCallback(game));
    EngineFacade::engine()->registerCallback("7", new LongbowmanSpawnCallback(game));
    EngineFacade::engine()->registerCallback("8", new HorsemanSpawnCallback(game));
    EngineFacade::engine()->registerCallback("9", new CatapultSpawnCallback(game));

    // Abilities
    EngineFacade::engine()->registerCallback("SPACE", new AttackCallback(game));
    EngineFacade::engine()->registerCallback("Q", new UseAbilityCallback(game, 0));
    EngineFacade::engine()->registerCallback("W", new UseAbilityCallback(game, 1));
    EngineFacade::engine()->registerCallback("E", new UseAbilityCallback(game, 2));
    EngineFacade::engine()->registerCallback("R", new UseAbilityCallback(game, 3));
    
    // Cheats
    EngineFacade::engine()->registerCallback("CTRL+1", new InfHealthCallback(game));
    EngineFacade::engine()->registerCallback("CTRL+2", new InfManaCallback(game));
    EngineFacade::engine()->registerCallback("CTRL+5", new InvisibleCallback(game));

}
