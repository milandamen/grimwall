//
// Created by dudebag on 11/30/16.
//
#include "TroupSpawnCallback.h"
TroupSpawnCallback::TroupSpawnCallback(IGame* game, std::string value) : KeypressCallback(game), value{value}
{

}

void TroupSpawnCallback::execute()
{
    if(value == "1"){
        EngineFacade::engine()->();
    }
}