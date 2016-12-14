//
// Created by stephanromer on 11/30/16.
//

#ifndef GRIMWALL_AGUIMANAGER_H
#define GRIMWALL_AGUIMANAGER_H


#include "Widget/GUIWidgetButton.h"
#include "Widget/GUIWidgetLabel.h"
#include "Widget/GUIWidgetImage.h"
#include "Widget/GUIWidgetRadio.h"

class AGUIManager {
public:
    virtual ~AGUIManager() = 0;
    virtual GUIWidgetButton* addButton(std::string caption = "", int x = 0, int y = 0) = 0;
    virtual GUIWidgetLabel* addLabel(std::string caption = "", int x = 0, int y = 0) = 0;
    virtual GUIWidgetImage* addImage(std::string asset = "", int x = 0, int y = 0, int width = 0, int height = 0) = 0;
    virtual GUIWidgetRadio* addRadio(std::string caption = "", std::string group = "", int x = 0, int y = 0, bool selected = false) = 0;
};


#endif //GRIMWALL_AGUIMANAGER_H
