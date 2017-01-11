
#ifndef GRIMWALL_AFIFECHANWIDGET_H
#define GRIMWALL_AFIFECHANWIDGET_H

#include <fifechan/widget.hpp>
#include "../../../../GUI/Widget/AGUIWidget.h"

class AFIFEChanWidget : virtual public AGUIWidget {
public:
    virtual ~AFIFEChanWidget() = default;
    virtual fcn::Widget* getWidget() = 0;
};


#endif //GRIMWALL_AFIFECHANWIDGET_H
