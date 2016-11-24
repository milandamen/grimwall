//
// Created by joost on 10/11/2016.
//

#include "GUI.h"


void GUI::addEventListener(string id, string event, void (*callback)() ) {
    this->eventListeners[id + event] = callback;
}

void GUI::removeEventListener(string id, string event) {
    if(this->eventListeners.count(id+event) > 0)
        this->eventListeners.erase(id+event);
}

void GUI::callEventListener(string id, string event) {
    if(this->eventListeners.count(id+event) > 0)
        this->eventListeners[id+event]();
}