//
// Created by stephanromer on 11/30/16.
//

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

#include "Widgets/FIFEChanButton.h"
#include "Widgets/FIFEChanLabel.h"
#include "Widgets/FIFEChanImage.h"
#include "Widgets/FIFEChanRadio.h"

class FIFEChanGuiManager : public AGUIManager {

private:
    fcn::Container* container {nullptr};
    std::vector<AGUIWidget*> widgets;
    int count = 0;



public:
    FIFEChanGuiManager();
    ~FIFEChanGuiManager();

    fcn::Container* getContainer();

    GUIWidgetButton* addButton(std::string caption, int x, int y) override;
    GUIWidgetLabel* addLabel(std::string caption, int x, int y) override;
    GUIWidgetImage* addImage(std::string asset, int x, int y, int width, int height) override;
    GUIWidgetRadio* addRadio(std::string caption, std::string group, int x, int y, bool selected) override;
};


#endif //GRIMWALL_FIFECHANGUIMANAGER_H
