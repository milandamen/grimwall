//
// Created by stephanromer on 12/14/16.
//

#ifndef GRIMWALL_GUIWIDGETRADIO_H
#define GRIMWALL_GUIWIDGETRADIO_H

#include <string>
#include <fifechan/widgets/radiobutton.hpp>
#include <functional>

#include "AGUIWidget.h"
#include "../../GUI/Widget/GUIWidgetRadio.h"


class GUIWidgetRadio : public virtual AGUIWidget {
protected:
    std::function<void()> onClickDelegate = [](){}; // Empty delegate

public:
    virtual void setCaption(std::string caption) = 0;
    virtual void setGroup(std::string group) = 0;
    virtual void setSelected(bool selected) = 0;
    virtual void onClick(std::function<void()> delegate) = 0;
};


#endif //GRIMWALL_GUIWIDGETRADIO_H
