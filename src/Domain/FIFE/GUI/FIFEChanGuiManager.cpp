
#include "FIFEChanGuiManager.h"
#include "Widget/FIFEChanImageButton.h"

FIFEChanGuiManager::FIFEChanGuiManager()
{
    this->container = new fcn::Container();
    this->container->setBackgroundColor(fcn::Color(0,0,0,0));
    this->container->setBaseColor(fcn::Color(0,0,0,0));
    this->container->setFocusable(false);
    this->container->setTabInEnabled(false);
    this->container->setTabOutEnabled(false);
    this->container->setEnabled(false);
    this->container->setX(0);
    this->container->setY(0);
    this->container->setWidth(EngineFacade::engine()->getScreenWidth());
    this->container->setHeight(EngineFacade::engine()->getScreenHeight());
}

FIFEChanGuiManager::~FIFEChanGuiManager()
{
    // Remove FCN widgets
    for (unsigned int i = 0; i < this->widgets.size(); i++) {
        delete this->widgets[i];
    }

    delete this->container;
}

fcn::Container* FIFEChanGuiManager::getContainer()
{
    return this->container;
}

GUIWidgetButton* FIFEChanGuiManager::addButton(std::string caption = "", int x = 0, int y = 0)
{
    FIFEChanButton* button = new FIFEChanButton();
    button->setX(x);
    button->setY(y);
    button->setWidth(300);
    button->setHeight(200);
    button->setCaption(caption);

    this->widgets.push_back(button);
    this->container->add(button->getWidget());

    return button;
}

GUIWidgetButton *FIFEChanGuiManager::createButton(std::string caption) {
    FIFEChanButton* button = new FIFEChanButton();
    button->setWidth(300);
    button->setHeight(200);
    button->setCaption(caption);

    this->widgets.push_back(button);

    return button;
}

GUIWidgetLabel* FIFEChanGuiManager::addLabel(std::string caption = "", int x = 0, int y = 0)
{
    FIFEChanLabel* label = new FIFEChanLabel();
    label->setX(x);
    label->setY(y);
    label->setCaption(caption);

    this->widgets.push_back(label);
    this->container->add(label->getWidget());

    return label;
}

GUIWidgetLabel *FIFEChanGuiManager::createLabel(std::string caption, int width = 200, int height = 20) {
    FIFEChanLabel* label = new FIFEChanLabel();
    label->setCaption(caption);
    label->setWidth(width);
    label->setHeight(height);

    this->widgets.push_back(label);

    return label;
}

GUIWidgetImage* FIFEChanGuiManager::addImage(std::string asset, int x = 0, int y = 0, int width = 0, int height = 0)
{
    FIFEChanImage* image = new FIFEChanImage();
    image->setX(x);
    image->setY(y);
    image->setWidth(width);
    image->setHeight(height);
    image->setAsset(asset);

    this->widgets.push_back(image);
    this->container->add(image->getWidget());

    return image;
}

GUIWidgetImage *FIFEChanGuiManager::createImage(std::string asset, int width, int height) {
    FIFEChanImage* image = new FIFEChanImage();
    image->setWidth(width);
    image->setHeight(height);
    image->setAsset(asset);

    this->widgets.push_back(image);

    return image;
}

GUIWidgetImageButton* FIFEChanGuiManager::addImageButton(std::string caption, std::string asset, int x = 0, int y = 0, int width = 0, int height = 0)
{
    FIFEChanImageButton* ib = new FIFEChanImageButton();
    ib->setX(x);
    ib->setY(y);
    ib->setWidth(width);
    ib->setHeight(height);
    ib->setCaption(caption);
    ib->setAsset(asset);

    this->widgets.push_back(ib);
    this->container->add(ib->getWidget());

    return ib;
}

GUIWidgetImageButton* FIFEChanGuiManager::createImageButton(std::string caption, std::string asset, int width = 0, int height = 0)
{
    FIFEChanImageButton* ib = new FIFEChanImageButton();
    ib->setWidth(width);
    ib->setHeight(height);
    ib->setCaption(caption);
    ib->setAsset(asset);

    this->widgets.push_back(ib);

    return ib;
}

GUIWidgetRadio* FIFEChanGuiManager::addRadio(std::string caption, std::string group, int x = 0, int y = 0, bool selected = false)
{
    FIFEChanRadio* radio = new FIFEChanRadio();
    radio->setX(x);
    radio->setY(y);
    radio->setWidth(200);
    radio->setHeight(20);
    radio->setCaption(caption);
    radio->setGroup(group);
    radio->setSelected(selected);

    this->widgets.push_back(radio);
    this->container->add(radio->getWidget());

    return radio;
}

GUIWidgetRadio *FIFEChanGuiManager::createRadio(std::string caption, std::string group, bool selected) {
    FIFEChanRadio* radio = new FIFEChanRadio();
    radio->setWidth(200);
    radio->setHeight(20);
    radio->setCaption(caption);
    radio->setGroup(group);
    radio->setSelected(selected);

    this->widgets.push_back(radio);

    return radio;
}

GUIWidgetContainer* FIFEChanGuiManager::addContainer(int x = 0, int y = 0, int width = 0, int height = 0)
{
    FIFEChanContainer* container = new FIFEChanContainer();
    container->setX(x);
    container->setY(y);
    container->setWidth(width);
    container->setHeight(height);

    this->widgets.push_back(container);
    this->container->add(container->getWidget());

    return container;
}

GUIWidgetContainer* FIFEChanGuiManager::createContainer(int width, int height) {
    FIFEChanContainer* container = new FIFEChanContainer();
    container->setWidth(width);
    container->setHeight(height);

    this->widgets.push_back(container);

    return container;
}


void FIFEChanGuiManager::setX(int x)
{
    this->container->setX(x);
}

void FIFEChanGuiManager::setY(int y)
{
    this->container->setY(y);
}

void FIFEChanGuiManager::setWidth(int width)
{
    this->container->setWidth(width);
}

void FIFEChanGuiManager::setHeight(int height)
{
    this->container->setHeight(height);
}
