
#ifndef GRIMWALL_FIFECHANGUIMANAGER_H
#define GRIMWALL_FIFECHANGUIMANAGER_H

#include <fifechan/actionlistener.hpp>
#include <fifechan/keylistener.hpp>
#include <fifechan/widgets/container.hpp>
#include <fifechan/widgets/button.hpp>
#include <vector>

#include "../../EngineFacade.h"
#include "../../../GUI/AGUIManager.h"
#include "../../../GUI/Widget/AGUIWidget.h"

#include "Widget/FIFEChanButton.h"
#include "Widget/FIFEChanLabel.h"
#include "Widget/FIFEChanImage.h"
#include "Widget/FIFEChanRadio.h"
#include "Widget/FIFEChanContainer.h"

class FIFEChanGuiManager : public AGUIManager {

private:
    fcn::Container* container {nullptr};
    std::vector<AGUIWidget*> widgets;

public:
    FIFEChanGuiManager();
    ~FIFEChanGuiManager();

    fcn::Container* getContainer();

    virtual GUIWidgetButton* addButton(std::string caption, int x, int y) override;
    virtual GUIWidgetButton *createButton(std::string caption) override;
    virtual GUIWidgetLabel* addLabel(std::string caption, int x, int y) override;
    virtual GUIWidgetLabel *createLabel(std::string caption, int width, int height) override;
    virtual GUIWidgetImage* addImage(std::string asset, int x, int y, int width, int height) override;
    virtual GUIWidgetImage *createImage(std::string asset, int width, int height) override;
    virtual GUIWidgetImageButton* addImageButton(std::string caption, std::string asset, int x, int y, int width, int height) override;
    virtual GUIWidgetImageButton* createImageButton(std::string caption, std::string asset, int width, int height) override;
    virtual GUIWidgetRadio* addRadio(std::string caption, std::string group, int x, int y, bool selected) override;
    virtual GUIWidgetRadio *createRadio(std::string caption, std::string group, bool selected) override;
    virtual GUIWidgetContainer* addContainer(int x, int y, int width, int height) override;
    virtual GUIWidgetContainer *createContainer(int width, int height) override;

    virtual void setX(int x);
    virtual void setY(int y);
    virtual void setWidth(int width);
    virtual void setHeight(int height);
};


#endif //GRIMWALL_FIFECHANGUIMANAGER_H
