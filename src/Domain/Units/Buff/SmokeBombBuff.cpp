#include "SmokeBombBuff.h"

SmokeBombBuff::SmokeBombBuff()
        : BuffDecorator("Smoke Bomb", 500)
{}

int SmokeBombBuff::getVisibility() {
    return 5;
}