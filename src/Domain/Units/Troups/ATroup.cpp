
#include "ATroup.h"

ATroup::ATroup(std::string name, int reach, int attackDelay, int moveSpeed, int power,
               int hitPoints, int visibility)
    :AUnit(name, reach, attackDelay, power, hitPoints, moveSpeed, visibility)
{

}

int ATroup::getMoveSpeed() {
    return this->moveSpeed;
}

int ATroup::getPrice() {
    return this->price;
}