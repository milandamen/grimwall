
#ifndef GRIMWALL_GUIWIDGETIMAGEBUTTON_H
#define GRIMWALL_GUIWIDGETIMAGEBUTTON_H

#include <string>
#include <functional>
#include "AGUIWidget.h"

class GUIWidgetImageButton : virtual public AGUIWidget {

protected:
    std::function<void()> onClickDelegate = [](){}; // Empty delegate
    std::function<void(AGUIWidget*)> onClickDelegateWithWidget = [](AGUIWidget* widget){};

public:
    virtual void setCaption(std::string caption) = 0;
    void onClick(std::function<void()> delegate);
    void onClick(std::function<void(AGUIWidget*)> delegate);
    virtual void setHighlightColor(int r, int g, int b, int a) = 0;
    virtual void setAsset(std::string asset) = 0;
};


#endif //GRIMWALL_GUIWIDGETIMAGEBUTTON_H
