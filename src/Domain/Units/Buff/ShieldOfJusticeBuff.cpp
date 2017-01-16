

#include "ShieldOfJusticeBuff.h"

ShieldOfJusticeBuff::ShieldOfJusticeBuff()
        : BuffDecorator("Shield of Justice", 300)
{}

int ShieldOfJusticeBuff::getVisibility() {
    return 0;
}