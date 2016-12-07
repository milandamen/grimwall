//
// Created by stephanromer on 11/30/16.
//

#ifndef GRIMWALL_BUTTON_H
#define GRIMWALL_BUTTON_H


#include "AGUIWidget.h"
#include <string>

class GuiWidgetButton : public AGUIWidget {

    typedef void (delegate)(void);

private:
    delegate onClickDelegate;

public:
    virtual ~GuiWidgetButton() = 0;

    virtual std::string getCaption() = 0;
    virtual void setCaption(std::string caption) = 0;
    virtual void onClick(delegate callback) = 0;
};


#endif //GRIMWALL_BUTTON_H
