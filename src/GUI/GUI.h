//
// Created by joost on 10/11/2016.
//

#ifndef GRIMWALL_GUI_H
#define GRIMWALL_GUI_H

#include "AGUIManager.h"

class GUI {

protected:
    AGUIManager* manager;


public:
    GUI(AGUIManager* manager);
    virtual ~GUI() = 0;

    void setGuiManager();
    AGUIManager* getGuiManager();
};


#endif //GRIMWALL_GUI_H
