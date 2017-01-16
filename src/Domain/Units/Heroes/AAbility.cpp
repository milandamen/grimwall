#include "AAbility.h"

AAbility::AAbility(std::string name, int cost)
        :name{name}, cost{cost}
{

}

std::string AAbility::getName() {
    return this->name;
}

int AAbility::getCost() {
    return this->cost;
}
