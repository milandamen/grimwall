#include "ATower.h"

ATower::ATower(std::string name, int reach, int attackDelay, int moveSpeed, int power, int hitPoints)
        : AUnit(name, reach, attackDelay, power, hitPoints){

}

ATower::~ATower() {

}

void ATower::doDamage(int power) {
    //do the attack
}