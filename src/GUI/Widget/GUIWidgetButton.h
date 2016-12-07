//
// Created by stephanromer on 11/30/16.
//

#ifndef GRIMWALL_BUTTON_H
#define GRIMWALL_BUTTON_H


#include "AGUIWidget.h"
#include <string>
#include <functional>

class GUIWidgetButton : public AGUIWidget {

protected:
    std::function<void()> onClickDelegate = [](){}; // Empty delegate

public:
    virtual void setCaption(std::string caption) = 0;
    void onClick(std::function<void()> delegate);
};


#endif //GRIMWALL_BUTTON_H
