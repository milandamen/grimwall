//
// Created by stephanromer on 11/30/16.
//

#ifndef GRIMWALL_FIFECHAN_H
#define GRIMWALL_FIFECHAN_H

#include <gui/fifechan/fifechanmanager.h>
#include <controller/engine.h>
#include <controller/enginesettings.h>

class FIFEChan {

private:
    FIFE::Engine* engine;
    FIFE::FifechanManager* guimanager;

public:
    FIFEChan(FIFE::Engine* engine);
    ~FIFEChan();

    void init();

    FIFE::FifechanManager* getGuiManager();
};


#endif //GRIMWALL_FIFECHAN_H
