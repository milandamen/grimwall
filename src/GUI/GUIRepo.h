
#ifndef GRIMWALL_GUIREPO_H
#define GRIMWALL_GUIREPO_H

#include <map>
#include <string>
#include "GUI.h"


class GUIRepo {

private:
    std::map<std::string, GUI*> guis;

public:
    GUIRepo();
    ~GUIRepo();

    void addGUI(std::string name, GUI* gui);
    GUI* getGUI(std::string name);
};


#endif //GRIMWALL_GUIREPO_H
