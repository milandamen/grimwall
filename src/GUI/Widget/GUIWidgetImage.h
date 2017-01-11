
#ifndef GRIMWALL_GUIWIDGETIMAGE_H
#define GRIMWALL_GUIWIDGETIMAGE_H

#include "AGUIWidget.h"
#include <string>

class GUIWidgetImage : virtual public AGUIWidget {
public:
    virtual void setAsset(std::string asset) = 0;
};


#endif //GRIMWALL_GUIWIDGETIMAGE_H
