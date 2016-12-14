//
// Created by stephanromer on 12/14/16.
//

#include "FIFEChanContainer.h"

FIFEChanContainer::FIFEChanContainer()
{
    this->container = new fcn::Container();
    this->container->setOpaque(true);
}

FIFEChanContainer::~FIFEChanContainer()
{
    delete this->container;
};

int FIFEChanContainer::getX() {
    return this->container->getChildrenArea().x;
}

void FIFEChanContainer::setX(int x) {
    this->container->setX(x);
}

int FIFEChanContainer::getY() {
    return this->container->getChildrenArea().y;
}

void FIFEChanContainer::setY(int y) {
    this->container->setY(y);
}

int FIFEChanContainer::getWidth() {
    return this->container->getChildrenArea().width;
}

void FIFEChanContainer::setWidth(int width)
{
    this->container->setWidth(width);
}

int FIFEChanContainer::getHeight() {
    return this->container->getChildrenArea().width;
}

void FIFEChanContainer::setHeight(int height){
    this->container->setHeight(height);
}

bool FIFEChanContainer::isVisible(){
    std::list<fcn::Widget*> widgets = this->container->getChildren();
    std::list<fcn::Widget*>::const_iterator it;

    bool visible = false;
    for(it = widgets.begin(); it != widgets.end(); ++it)
        if(visible != (*it)->isVisible())
            return !visible;

    return visible;
}

void FIFEChanContainer::setVisible(bool visible)
{
    std::list<fcn::Widget*> widgets = this->container->getChildren();
    std::list<fcn::Widget*>::const_iterator it;
    for(it = widgets.begin(); it != widgets.end(); ++it)
        (*it)->setVisible(visible);
}

fcn::Widget* FIFEChanContainer::getWidget() {
    return this->container;
}

void FIFEChanContainer::addWidget(AGUIWidget* widget, int x = 0, int y = 0)
{
    this->container->add(dynamic_cast<AFIFEChanWidget*>(widget)->getWidget(), x, y);
}

void FIFEChanContainer::removeWidget(AGUIWidget *widget)
{
    this->container->remove(dynamic_cast<AFIFEChanWidget*>(widget)->getWidget());
}

void FIFEChanContainer::setForegroundColor(int r = 0, int g = 0, int b = 0, int a = 0)
{
    this->container->setForegroundColor(fcn::Color(r, g, b, a));
}

void FIFEChanContainer::setBackgroundColor(int r = 0, int g = 0, int b = 0, int a = 0)
{
    this->container->setBaseColor(fcn::Color(r, g, b, a));
    this->container->setBackgroundColor(fcn::Color(r, g, b, a));
}