#include "AAbility.h"

AAbility::AAbility(int cost)
        :cost{cost}
{

}

int AAbility::getCost() {
    return this->cost;
}
