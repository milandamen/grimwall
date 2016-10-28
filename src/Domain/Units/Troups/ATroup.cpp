
#include "ATroup.h"
#include "../AUnit.h"

ATroup::ATroup(std::string name, int moveSpeed, int price, int range, int attackDelay, int power, int hitPoints)
    : name{name}, moveSpeed{moveSpeed}, price{price}, range{range},
      attackDelay{attackDelay}, power{power}, hitPoints{hitPoints}
{}

int ATroup::getPrice()
{
    return this->price;
}

ATroup::~ATroup()
{}