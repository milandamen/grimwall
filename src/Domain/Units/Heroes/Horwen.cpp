//
// Created by baksteen on 10/24/16.
//

#include "Horwen.h"
#include "Abilities/Rage.h"
#include "Abilities/Execution.h"
#include "Abilities/ShieldOfJustice.h"
#include "Abilities/StrikeOfReflection.h"

Horwen::Horwen() : AHero("Horwen", 4, 600, 5, 150, 250, 100) {
    abilities.push_back(new ShieldOfJustice());
    abilities.push_back(new Rage());
    abilities.push_back(new Execution());
    abilities.push_back(new StrikeOfReflection());

}

Horwen::~Horwen(){
    for(auto i = 0; i < abilities.size(); ++i){
        delete abilities[i];
    }
    abilities.clear();
}



void Horwen::doDamage(int power) {

}