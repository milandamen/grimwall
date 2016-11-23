#include "FIFEKeyListener.h"

FIFEKeyListener::FIFEKeyListener(IGame* game)
: game(game)
{
    
}

FIFEKeyListener::~FIFEKeyListener()
{
    for (auto it : callbackMap)
    {
        delete it.second;
    }
}

void FIFEKeyListener::registerCallback(std::string keys, ICallback* callback)
{
    bool hasCtrl {false};
    bool hasShift {false};
    bool hasAlt {false};
    std::vector<std::string> elems;
    std::stringstream ss;
    ss.str(keys);
    std::string item;
    while (std::getline(ss, item, '+')) {
        elems.push_back(item);
        if (item == "CTRL" || item == "LEFT_CONTROL" || item == "RIGHT_CONTROL") hasCtrl = true;
        if (item == "SHIFT" || item == "LEFT_SHIFT" || item == "RIGHT_SHIFT") hasShift = true;
        if (item == "ALT" || item == "LEFT_ALT" || item == "RIGHT_ALT") hasAlt = true;
    }
    
    std::stringstream ssnew;
    if (hasCtrl)
    {
        ssnew << "CTRL";
    }
    if (hasShift)
    {
        ssnew << "SHIFT";
    }
    if (hasAlt)
    {
        ssnew << "ALT";
    }
    
    for (auto& el : elems)
    {
        if (el != "CTRL" && el != "LEFT_CONTROL" && el != "RIGHT_CONTROL" && el != "SHIFT" && el != "LEFT_SHIFT" && el != "RIGHT_SHIFT" && el != "ALT" && el != "LEFT_ALT" && el != "RIGHT_ALT")
        {
            ssnew << el;
        }
    }
    
    std::cout << "registered " << keys << std::endl;
    callbackMap.insert({ssnew.str(), callback});
}

/**
 * overridden function from base class
 * this function is called when a key is pressed
 * and will be repeatedly called when the key is held down
 */
void FIFEKeyListener::keyPressed(FIFE::KeyEvent& evt)
{
    std::stringstream ss;
    if (evt.isControlPressed())
    {
        ss << "CTRL";
    }
    if (evt.isShiftPressed())
    {
        ss << "SHIFT";
    }
    if (evt.isAltPressed())
    {
        ss << "ALT";
    }
    
    std::string key {evt.getKey().getAsString()};
    std::transform(key.begin(), key.end(), key.begin(), std::ptr_fun<int, int>(std::toupper));
    ss << key;
    std::string pressed = ss.str();
    
    for (auto& keyPair : callbackMap)
    {
        if (keyPair.first == pressed)
        {
            // Run execute() on the ICallback
            keyPair.second->execute();
            
            // Mark event as consumed
            evt.consume();
            return;
        }
    }
}

/**
 * overridden function from base class
 * this function is called when a key is released
 */
void FIFEKeyListener::keyReleased(FIFE::KeyEvent& evt)
{
    // Mark event as consumed
    evt.consume();
}
