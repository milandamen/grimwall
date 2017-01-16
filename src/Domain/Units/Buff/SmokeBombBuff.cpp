#include "SmokeBombBuff.h"

SmokeBombBuff::SmokeBombBuff(IUnit *inner)
        : BuffDecorator{inner, 5000}
{}

int SmokeBombBuff::getVisibility() {
    return 0;
}