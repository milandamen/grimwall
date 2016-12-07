//
// Created by stephanromer on 11/30/16.
//

#ifndef GRIMWALL_AGUIMANAGER_H
#define GRIMWALL_AGUIMANAGER_H


#include "Widget/GUIWidgetButton.h"
#include "Widget/GUIWidgetLabel.h"
#include "Widget/GUIWidgetImage.h"

class AGUIManager {
public:
    virtual GUIWidgetButton* addButton() = 0;
    virtual GUIWidgetLabel* addLabel() = 0;
    virtual GUIWidgetImage* addImage() = 0;
};


#endif //GRIMWALL_AGUIMANAGER_H
