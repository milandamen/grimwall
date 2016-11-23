#ifndef FIFE_KEY_LISTENER_H
#define FIFE_KEY_LISTENER_H

#include "eventchannel/key/ec_ikeylistener.h"
#include "eventchannel/key/ec_keyevent.h"
#include "eventchannel/key/ec_key.h"

#include <unordered_map>
#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>

#include "../IGame.h"
#include "../../Input/ICallback.h"

//! handler for listening to keyboard input
class FIFEKeyListener : public FIFE::IKeyListener
{
private:
    IGame* game;
    std::unordered_map<std::string, ICallback*> callbackMap;
public:
    FIFEKeyListener(IGame* game);
    ~FIFEKeyListener();
    
    void registerCallback(std::string keys, ICallback* callback);

    // overridden from base class
    virtual void keyPressed(FIFE::KeyEvent& evt) override;
    virtual void keyReleased(FIFE::KeyEvent& evt) override;
};

#endif
