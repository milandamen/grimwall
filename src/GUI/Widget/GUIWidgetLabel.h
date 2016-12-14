//
// Created by stephanromer on 12/7/16.
//

#ifndef GRIMWALL_GUIWIDGETLABEL_H
#define GRIMWALL_GUIWIDGETLABEL_H

#include <string>
#include "AGUIWidget.h"
#include "GUITextAlignment.h"


class GUIWidgetLabel : virtual public AGUIWidget {
public:
    virtual void setCaption(std::string caption) = 0;
    virtual void setAlignment(GUITextAlignment alignment) = 0;
};


#endif //GRIMWALL_GUIWIDGETLABEL_H
