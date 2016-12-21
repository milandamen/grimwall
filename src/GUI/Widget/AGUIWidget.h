
#ifndef GRIMWALL_AGUIWIDGET_H
#define GRIMWALL_AGUIWIDGET_H

#include <string>

class AGUIWidget {
protected:
    std::string identifier {""};
public:
    virtual ~AGUIWidget() = default;

    std::string getIdentifier();
    void setIdentifier(std::string identifier);

    virtual int getWidth() = 0;
    virtual void setWidth(int width) = 0;
    virtual int getHeight() = 0;
    virtual void setHeight(int height) = 0;
    virtual int getX() = 0;
    virtual void setX(int x) = 0;
    virtual int getY() = 0;
    virtual void setY(int y) = 0;
    virtual bool isVisible() = 0;
    virtual void setVisible(bool visible) = 0;
    virtual void setForegroundColor(int r, int g, int b, int a) = 0;
    virtual void setBackgroundColor(int r, int g, int b, int a) = 0;
};


#endif //GRIMWALL_AGUIWIDGET_H
