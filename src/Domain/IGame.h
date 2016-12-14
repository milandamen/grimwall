#ifndef IGAME_H
#define IGAME_H

#include "Units/Heroes/AHero.h"
#include "Units/UnitManager.hpp"

class IGame
{
public:
    virtual void setMap(std::string path) = 0;
    virtual void setPaused(bool paused) = 0;
    virtual void setHero(AHero* hero) = 0;
    virtual void setUI(std::string name) = 0;
    virtual int getCurrentScore() = 0;
    virtual UnitManager<AHero>* getHero() = 0;
    virtual void quit() = 0;
};

#endif