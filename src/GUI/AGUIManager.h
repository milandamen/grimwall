
#ifndef GRIMWALL_AGUIMANAGER_H
#define GRIMWALL_AGUIMANAGER_H


#include "Widget/GUIWidgetButton.h"
#include "Widget/GUIWidgetLabel.h"
#include "Widget/GUIWidgetImage.h"
#include "Widget/GUIWidgetRadio.h"
#include "Widget/GUIWidgetContainer.h"

class AGUIManager {
public:
    virtual ~AGUIManager() = default;
    virtual GUIWidgetButton* addButton(std::string caption = "", int x = 0, int y = 0) = 0;
    virtual GUIWidgetButton* createButton(std::string caption = "") = 0;
    virtual GUIWidgetLabel* addLabel(std::string caption = "", int x = 0, int y = 0) = 0;
    virtual GUIWidgetLabel* createLabel(std::string caption = "", int width = 200, int height = 20) = 0;
    virtual GUIWidgetImage* addImage(std::string asset = "", int x = 0, int y = 0, int width = 0, int height = 0) = 0;
    virtual GUIWidgetImage* createImage(std::string asset = "", int width = 0, int height = 0) = 0;
    virtual GUIWidgetRadio* addRadio(std::string caption = "", std::string group = "", int x = 0, int y = 0, bool selected = false) = 0;
    virtual GUIWidgetRadio* createRadio(std::string caption = "", std::string group = "", bool selected = false) = 0;
    virtual GUIWidgetContainer* addContainer(int x = 0, int y = 0, int width = 0, int height = 0) = 0;
    virtual GUIWidgetContainer* createContainer(int width = 0, int height = 0) = 0;

    virtual void setX(int x) = 0;
    virtual void setY(int y) = 0;
    virtual void setWidth(int width) = 0;
    virtual void setHeight(int height) = 0;
};


#endif //GRIMWALL_AGUIMANAGER_H
