
#ifndef GRIMWALL_ENGINEFACADE_H
#define GRIMWALL_ENGINEFACADE_H

#include <iostream>
#include "IEngineFacade.h"
#include "FIFE/FIFEFacade.h"

/**
 * Manager of which enginefacade to use
 */
class EngineFacade {
private:
    static IEngineFacade* _engine;
    static std::string currentEngineName;
    
    EngineFacade();
    ~EngineFacade();
public:
    static IEngineFacade* engine();
    static void setEngine(std::string engine);
    static void destroy();
};


#endif
