//
// Created by stephanromer on 11/30/16.
//

#ifndef GRIMWALL_AGUIMANAGER_H
#define GRIMWALL_AGUIMANAGER_H


class AGUIManager {
protected:
    AGUIManager() {};
    virtual ~AGUIManager() = 0;

    virtual void addButton() = 0;
    virtual void addLabel() = 0;
    virtual void addImage() = 0;
};


#endif //GRIMWALL_AGUIMANAGER_H
