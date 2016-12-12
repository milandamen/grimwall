#include "../Domain/EngineFacade.h"
#include "Callbacks/MoveCameraCallback.h"
#include "Callbacks/ZoomCameraCallback.h"
#include "../Domain/IGame.h"

class MouseMapper
{
public:
    MouseMapper(IGame* game);
};