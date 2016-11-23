//
// Created by joost on 10/11/2016.
//

#ifndef GRIMWALL_GUI_H
#define GRIMWALL_GUI_H

#include <map>

using namespace std;

class GUI {

private:
    typedef void (*eventListener)();
    std::map<string, eventListener> eventListeners;
    void callEventListener(string id, string event);

public:
    void addEventListener(string id, string event, void (*callback)());
    void removeEventListener(string id, string event);
};


#endif //GRIMWALL_GUI_H
