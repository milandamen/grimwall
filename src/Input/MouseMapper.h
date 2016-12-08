#include "../Domain/EngineFacade.h"
#include "Callbacks/MoveCameraCallback.h"
#include "Callbacks/ZoomCameraCallback.h"
#include "Callbacks/MoveCallback.h"
#include "../Domain/IGame.h"

class MouseMapper
{
public:
    MouseMapper(IGame* game);
};