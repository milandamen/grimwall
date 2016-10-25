//
// Created by baksteen on 10/24/16.
//

#include "Horwen.h"
#include "Abilities/Rage.h"
#include "../Buff/RageBuff.h"

Horwen::Horwen() : AHero("Horwen", 4, 600, 5, 150, 250){
    this->moveSpeed = moveSpeed;
}


void Horwen::activateRage() {
    RageBuff *buff = new RageBuff(this, 2);

    attackDelay = buff->getAttackDelay();

    delete buff;
}

void Horwen::doDamage(int power) {

}