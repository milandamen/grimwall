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
    virtual GUIWidgetButton* addButton(std::string caption = "", int x = 0, int y = 0) = 0;
    virtual GUIWidgetLabel* addLabel(std::string caption = "", int x = 0, int y = 0) = 0;
    virtual GUIWidgetImage* addImage(std::string asset = "", int x = 0, int y = 0) = 0;
};


#endif //GRIMWALL_AGUIMANAGER_H
