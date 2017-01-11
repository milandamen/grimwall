
#include "ATroup.h"

ATroup::ATroup(std::string name, int reach, int attackDelay, int moveSpeed, int power,
               int hitPoints, int visibility)
    :AUnit(name, reach, attackDelay, power, hitPoints, moveSpeed, visibility) {

}
