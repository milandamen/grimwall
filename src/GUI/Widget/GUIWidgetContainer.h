
#ifndef GRIMWALL_GUIWIDGETCONTAINER_H
#define GRIMWALL_GUIWIDGETCONTAINER_H

#include "AGUIWidget.h"

class GUIWidgetContainer : virtual public AGUIWidget {
public:
    virtual void addWidget(AGUIWidget* widget, int x = 0, int y = 0) = 0;
    virtual void removeWidget(AGUIWidget* widget) = 0;
};


#endif //GRIMWALL_GUIWIDGETCONTAINER_H
