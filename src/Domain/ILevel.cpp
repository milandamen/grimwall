//
// Created by stephanromer on 1/16/17.
//

#include "ILevel.h"

std::string ILevel::getMap() {
    return this->map;
}

int ILevel::getSpawnHeroX() {
    return this->spawnHeroX;
}

int ILevel::getSpawnHeroY() {
    return this->spawnHeroY;
}