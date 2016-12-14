//
// Created by stephanromer on 11/30/16.
//

#ifndef GRIMWALL_BUTTON_H
#define GRIMWALL_BUTTON_H


#include "AGUIWidget.h"
#include <string>
#include <functional>

class GUIWidgetButton : virtual public AGUIWidget {

protected:
    std::function<void()> onClickDelegate = [](){}; // Empty delegate
    std::function<void(AGUIWidget*)> onClickDelegateWithWidget = [](AGUIWidget* widget){};

public:
    virtual void setCaption(std::string caption) = 0;
    virtual void onClick(std::function<void()> delegate);
    virtual void onClick(std::function<void(AGUIWidget*)> delegate);
    virtual void setHighlightColor(int r, int g, int b, int a) = 0;
};


#endif //GRIMWALL_BUTTON_H
