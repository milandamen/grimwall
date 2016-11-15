#include "Horwen.h"
#include "Abilities/Rage.h"
#include "../Buff/RageBuff.h"

using namespace std;

Horwen::Horwen() : AHero("Horwen", 4, 600, 5, 150, 250){
    this->moveSpeed = moveSpeed;
//    abilities.push_back(new Rage());
}

Horwen::~Horwen(){}


void Horwen::activateRage() {
    RageBuff *buff = new RageBuff(this, 2);

    this->attackDelay = buff->getAttackDelay();

    delete buff;
}

string Horwen::getName() {return "Horwen";}
int Horwen::getReach(){ return 0;}
int Horwen::getAttackDelay(){ return attackDelay;}
int Horwen::getPower(){ return 0;}
int Horwen::getHitPoints(){ return 0;}
int Horwen::getOriginalHitPoints(){ return 0;}
void Horwen::doDamage(int power) {

}