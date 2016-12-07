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
    
    std::vector<std::string> keyList;
    if (hasCtrl)
    {
        keyList.push_back("CTRL");
    }
    if (hasShift)
    {
        keyList.push_back("SHIFT");
    }
    if (hasAlt)
    {
        keyList.push_back("ALT");
    }
    
    for (auto& el : elems)
    {
        if (el != "CTRL" && el != "LEFT_CONTROL" && el != "RIGHT_CONTROL" && el != "SHIFT" && el != "LEFT_SHIFT" && el != "RIGHT_SHIFT" && el != "ALT" && el != "LEFT_ALT" && el != "RIGHT_ALT")
        {
            keyList.push_back(el);
        }
    }
    
    // Sort keyList
    std::sort(keyList.begin(), keyList.end());
    
    std::stringstream ssnew;
    for (auto& el : keyList)
    {
        ssnew << el;
    }
    
    callbackMap.insert({ssnew.str(), callback});
}

/**
 * overridden function from base class
 * this function is called when a key is pressed
 * and will be repeatedly called when the key is held down
 */
void FIFEKeyListener::keyPressed(FIFE::KeyEvent& evt)
{
    std::string key {evt.getKey().getAsString()};
    std::transform(key.begin(), key.end(), key.begin(), std::ptr_fun<int, int>(std::toupper));
    
    if (key == "CTRL" || key == "LEFT CTRL" || key == "RIGHT CTRL")
    {
        key = "CTRL";
    }
    else if (key == "SHIFT" || key == "LEFT SHIFT" || key == "RIGHT SHIFT")
    {
        key = "SHIFT";
    }
    if (key == "ALT" || key == "LEFT ALT" || key == "RIGHT ALT")
    {
        key = "ALT";
    }
    
    addPressed(key);
}

/**
 * overridden function from base class
 * this function is called when a key is released
 */
void FIFEKeyListener::keyReleased(FIFE::KeyEvent& evt)
{
    std::string key {evt.getKey().getAsString()};
    std::transform(key.begin(), key.end(), key.begin(), std::ptr_fun<int, int>(std::toupper));
    
    if (key == "CTRL" || key == "LEFT CTRL" || key == "RIGHT CTRL")
    {
        key = "CTRL";
    }
    else if (key == "SHIFT" || key == "LEFT SHIFT" || key == "RIGHT SHIFT")
    {
        key = "SHIFT";
    }
    if (key == "ALT" || key == "LEFT ALT" || key == "RIGHT ALT")
    {
        key = "ALT";
    }
    
    removePressed(key);
    
    // Mark event as consumed
    evt.consume();
}

void FIFEKeyListener::addPressed(std::string key)
{
    if(std::find(pressedKeys.begin(), pressedKeys.end(), key) != pressedKeys.end()) {
        /* v contains x */
    } else {
        pressedKeys.push_back(key);
        loadCallback();
    }
}

void FIFEKeyListener::removePressed(std::string key)
{
    pressedKeys.erase(std::remove(pressedKeys.begin(), pressedKeys.end(), key), pressedKeys.end());
    loadCallback();
}

void FIFEKeyListener::loadCallback()
{
    // This method only runs when pressedKeys changed
    
    if (loadedCallback != nullptr)
    {
        loadedCallback->reset();
        loadedCallback = nullptr;
    }
    
    // Sort keyList
    std::sort(pressedKeys.begin(), pressedKeys.end());
    
    std::stringstream ss;
    for (auto& el : pressedKeys)
    {
        ss << el;
    }
    
    std::string needle = ss.str();
    
    // Find callback
    for (auto& keyPair : callbackMap)
    {
        if (keyPair.first == needle)
        {
            loadedCallback = keyPair.second;
            break;
        }
    }
}

void FIFEKeyListener::tick()
{
    if (loadedCallback == nullptr) { return; }
    
    loadedCallback->execute();
}

