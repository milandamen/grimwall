//
// Created by stephanromer on 11/30/16.
//

#ifndef GRIMWALL_AGUIWIDGET_H
#define GRIMWALL_AGUIWIDGET_H


class AGUIWidget {

public:
    AGUIWidget();
    virtual ~AGUIWidget() = 0;

    virtual void setWidth(int width) = 0;
    virtual void setHeight(int height) = 0;
    virtual void setX(int x) = 0;
    virtual void setY(int y) = 0;
};


#endif //GRIMWALL_AGUIWIDGET_H
