#include "KeyboardMapper.h"

KeyboardMapper::KeyboardMapper()
{
    EngineFacade::engine()->registerCallback("CTRL+W",nullptr);
}