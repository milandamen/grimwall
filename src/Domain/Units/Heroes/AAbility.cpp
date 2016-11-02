#include "AAbility.h"

AAbility::AAbility(int cost)
        :cost{cost}
{

}

AAbility::~AAbility()
{

}

int AAbility::getCost() {
    return this->cost;
}
