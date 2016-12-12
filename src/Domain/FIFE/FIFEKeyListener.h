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
    IGame* game {nullptr};
    std::unordered_map<std::string, ICallback*> callbackMap;
    std::vector<std::string> pressedKeys;
    ICallback* loadedCallback {nullptr};
    
    void addPressed(std::string key);
    void removePressed(std::string key);
    void loadCallback();
    std::string generalizeModifier(std::string key);
public:
    FIFEKeyListener(IGame* game);
    ~FIFEKeyListener();
    
    void registerCallback(std::string keys, ICallback* callback);
    void tick();

    // overridden from base class
    virtual void keyPressed(FIFE::KeyEvent& evt) override;
    virtual void keyReleased(FIFE::KeyEvent& evt) override;
};

#endif
