#include "KeyboardMapper.h"


KeyboardMapper::KeyboardMapper(IGame* game)
{
    // SYSTEM
    EngineFacade::engine()->registerCallback("ESCAPE", new QuitCallback(game));
    

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
}
