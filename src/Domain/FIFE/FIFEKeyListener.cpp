#include "FIFEKeyListener.h"

FIFEKeyListener::FIFEKeyListener(Game* game)
: game(game)
{
    this->setKeyMap();
    
    callbackMap.insert({"asd",nullptr});
}

FIFEKeyListener::~FIFEKeyListener()
{
    for (auto it : callbackMap)
    {
        delete it.second;
    }
    
    delete keyMap;
}

void FIFEKeyListener::registerCallback(std::string keys, ICallback* callback)
{
    callbackMap.insert({keys, callback});
}

/**
 * overridden function from base class
 * this function is called when a key is pressed
 * and will be repeatedly called when the key is held down
 */
void FIFEKeyListener::keyPressed(FIFE::KeyEvent& evt)
{
    
}

/**
 * overridden function from base class
 * this function is called when a key is released
 */
void FIFEKeyListener::keyReleased(FIFE::KeyEvent& evt)
{
    game->quit();
    
    // mark event as consumed
    evt.consume();
    
    // map event key value to a game action
//     switch (evt.getKey().getValue())
//     {
//         case FIFE::Key::ESCAPE:
//         {
//             m_parent->Quit();
//             break;
//         }
//         case FIFE::Key::LEFT:
//         {
//             m_parent->GetViewController()->RotateLeft();
//             break;
//         }
//         case FIFE::Key::RIGHT:
//         {
//             m_parent->GetViewController()->RotateRight();
//             break;
//         }
//         case FIFE::Key::UP:
//         {
//             m_parent->GetViewController()->ZoomIn();
//             break;
//         }
//         case FIFE::Key::DOWN:
//         {
//             m_parent->GetViewController()->ZoomOut();
//             break;
//         }
//         case FIFE::Key::BACKQUOTE:
//         {
//             m_parent->toggleConsole();
//             break;
//         }
//         default:
//         {
//             break;
//         }
//     }
// 
//     // mark event as consumed
//     evt.consume();
}

void FIFEKeyListener::setKeyMap()
{
    keyMap = new std::unordered_map<std::string, FIFE::Key::KeyType>;
    
    keyMap->insert({
        {"INVALID_KEY", FIFE::Key::INVALID_KEY},
        {"ENTER", FIFE::Key::ENTER},
        {"ESCAPE", FIFE::Key::ESCAPE},
        {"BACKSPACE", FIFE::Key::BACKSPACE},
        {"TAB", FIFE::Key::TAB},
        {"SPACE", FIFE::Key::SPACE},
        {"EXCLAIM", FIFE::Key::EXCLAIM},
        {"QUOTEDBL", FIFE::Key::QUOTEDBL},
        {"HASH", FIFE::Key::HASH},
        {"PERCENT", FIFE::Key::PERCENT},
        {"DOLLAR", FIFE::Key::DOLLAR},
        {"AMPERSAND", FIFE::Key::AMPERSAND},
        {"QUOTE", FIFE::Key::QUOTE},
        {"LEFTPAREN", FIFE::Key::LEFTPAREN},
        {"RIGHTPAREN", FIFE::Key::RIGHTPAREN},
        {"ASTERISK", FIFE::Key::ASTERISK},
        {"PLUS", FIFE::Key::PLUS},
        {"COMMA", FIFE::Key::COMMA},
        {"MINUS", FIFE::Key::MINUS},
        {"PERIOD", FIFE::Key::PERIOD},
        {"SLASH", FIFE::Key::SLASH},
        {"NUM_0", FIFE::Key::NUM_0},
        {"NUM_1", FIFE::Key::NUM_1},
        {"NUM_2", FIFE::Key::NUM_2},
        {"NUM_3", FIFE::Key::NUM_3},
        {"NUM_4", FIFE::Key::NUM_4},
        {"NUM_5", FIFE::Key::NUM_5},
        {"NUM_6", FIFE::Key::NUM_6},
        {"NUM_7", FIFE::Key::NUM_7},
        {"NUM_8", FIFE::Key::NUM_8},
        {"NUM_9", FIFE::Key::NUM_9},
        {"COLON", FIFE::Key::COLON},
        {"SEMICOLON", FIFE::Key::SEMICOLON},
        {"LESS", FIFE::Key::LESS},
        {"EQUALS", FIFE::Key::EQUALS},
        {"GREATER", FIFE::Key::GREATER},
        {"QUESTION", FIFE::Key::QUESTION},
        {"AT", FIFE::Key::AT},
        {"LEFTBRACKET", FIFE::Key::LEFTBRACKET},
        {"BACKSLASH", FIFE::Key::BACKSLASH},
        {"RIGHTBRACKET", FIFE::Key::RIGHTBRACKET},
        {"CARET", FIFE::Key::CARET},
        {"UNDERSCORE", FIFE::Key::UNDERSCORE},
        {"BACKQUOTE", FIFE::Key::BACKQUOTE},
        {"A", FIFE::Key::A},
        {"B", FIFE::Key::B},
        {"C", FIFE::Key::C},
        {"D", FIFE::Key::D},
        {"E", FIFE::Key::E},
        {"F", FIFE::Key::F},
        {"G", FIFE::Key::G},
        {"H", FIFE::Key::H},
        {"I", FIFE::Key::I},
        {"J", FIFE::Key::J},
        {"K", FIFE::Key::K},
        {"L", FIFE::Key::L},
        {"M", FIFE::Key::M},
        {"N", FIFE::Key::N},
        {"O", FIFE::Key::O},
        {"P", FIFE::Key::P},
        {"Q", FIFE::Key::Q},
        {"R", FIFE::Key::R},
        {"S", FIFE::Key::S},
        {"T", FIFE::Key::T},
        {"U", FIFE::Key::U},
        {"V", FIFE::Key::V},
        {"W", FIFE::Key::W},
        {"X", FIFE::Key::X},
        {"Y", FIFE::Key::Y},
        {"Z", FIFE::Key::Z},

        {"CAPS_LOCK", FIFE::Key::CAPS_LOCK},

        {"F1", FIFE::Key::F1},
        {"F2", FIFE::Key::F2},
        {"F3", FIFE::Key::F3},
        {"F4", FIFE::Key::F4},
        {"F5", FIFE::Key::F5},
        {"F6", FIFE::Key::F6},
        {"F7", FIFE::Key::F7},
        {"F8", FIFE::Key::F8},
        {"F9", FIFE::Key::F9},
        {"F10", FIFE::Key::F10},
        {"F11", FIFE::Key::F11},
        {"F12", FIFE::Key::F12},

        {"PRINT_SCREEN", FIFE::Key::PRINT_SCREEN},
        {"SCROLL_LOCK", FIFE::Key::SCROLL_LOCK},
        {"PAUSE", FIFE::Key::PAUSE},
        {"INSERT", FIFE::Key::INSERT},
        {"HOME", FIFE::Key::HOME},
        {"PAGE_UP", FIFE::Key::PAGE_UP},
        {"DELETE", FIFE::Key::DELETE},
        {"END", FIFE::Key::END},
        {"PAGE_DOWN", FIFE::Key::PAGE_DOWN},
        {"RIGHT", FIFE::Key::RIGHT},
        {"LEFT", FIFE::Key::LEFT},
        {"DOWN", FIFE::Key::DOWN},
        {"UP", FIFE::Key::UP},

        {"NUM_LOCK", FIFE::Key::NUM_LOCK},
        {"KP_DIVIDE", FIFE::Key::KP_DIVIDE},
        {"KP_MULTIPLY", FIFE::Key::KP_MULTIPLY},
        {"KP_MINUS", FIFE::Key::KP_MINUS},
        {"KP_PLUS", FIFE::Key::KP_PLUS},
        {"KP_ENTER", FIFE::Key::KP_ENTER},
        {"KP_0", FIFE::Key::KP_0},
        {"KP_1", FIFE::Key::KP_1},
        {"KP_2", FIFE::Key::KP_2},
        {"KP_3", FIFE::Key::KP_3},
        {"KP_4", FIFE::Key::KP_4},
        {"KP_5", FIFE::Key::KP_5},
        {"KP_6", FIFE::Key::KP_6},
        {"KP_7", FIFE::Key::KP_7},
        {"KP_8", FIFE::Key::KP_8},
        {"KP_9", FIFE::Key::KP_9},
        {"KP_PERIOD", FIFE::Key::KP_PERIOD},

        {"APPLICATION", FIFE::Key::APPLICATION},
        {"POWER", FIFE::Key::POWER},
        {"KP_EQUALS", FIFE::Key::KP_EQUALS},
        {"F13", FIFE::Key::F13},
        {"F14", FIFE::Key::F14},
        {"F15", FIFE::Key::F15},
        {"F16", FIFE::Key::F16},
        {"F17", FIFE::Key::F17},
        {"F18", FIFE::Key::F18},
        {"F19", FIFE::Key::F19},
        {"F20", FIFE::Key::F20},
        {"F21", FIFE::Key::F21},
        {"F22", FIFE::Key::F22},
        {"F23", FIFE::Key::F23},
        {"F24", FIFE::Key::F24},
        {"EXECUTE", FIFE::Key::EXECUTE},
        {"HELP", FIFE::Key::HELP},
        {"MENU", FIFE::Key::MENU},
        {"SELECT", FIFE::Key::SELECT},
        {"STOP", FIFE::Key::STOP},
        {"AGAIN", FIFE::Key::AGAIN},
        {"UNDO", FIFE::Key::UNDO},
        {"CUT", FIFE::Key::CUT},
        {"COPY", FIFE::Key::COPY},
        {"PASTE", FIFE::Key::PASTE},
        {"FIND", FIFE::Key::FIND},
        {"MUTE", FIFE::Key::MUTE},
        {"VOLUME_UP", FIFE::Key::VOLUME_UP},
        {"VOLUME_DOWN", FIFE::Key::VOLUME_DOWN},
        {"KP_COMMA", FIFE::Key::KP_COMMA},
        {"KP_EQUALSAS400", FIFE::Key::KP_EQUALSAS400},

        {"ERASE", FIFE::Key::ERASE},
        {"SYS_REQ", FIFE::Key::SYS_REQ},
        {"CANCEL", FIFE::Key::CANCEL},
        {"CLEAR", FIFE::Key::CLEAR},
        {"PRIOR", FIFE::Key::PRIOR},
        {"RETURN", FIFE::Key::RETURN},
        {"SEPARATOR", FIFE::Key::SEPARATOR},
        {"FORTH", FIFE::Key::FORTH},
        {"OPER", FIFE::Key::OPER},
        {"CLEAR_AGAIN", FIFE::Key::CLEAR_AGAIN},
        {"CR_SEL", FIFE::Key::CR_SEL},
        {"EX_SEL", FIFE::Key::EX_SEL},

        {"KP_00", FIFE::Key::KP_00},
        {"KP_000", FIFE::Key::KP_000},
        {"THOUSANDS_SEPARATOR", FIFE::Key::THOUSANDS_SEPARATOR},
        {"DECIMAL_SEPARATOR", FIFE::Key::DECIMAL_SEPARATOR},
        {"CURRENCY_UNIT", FIFE::Key::CURRENCY_UNIT},
        {"CURRENCY_SUBUNIT", FIFE::Key::CURRENCY_SUBUNIT},
        {"KP_LEFTPAREN", FIFE::Key::KP_LEFTPAREN},
        {"KP_RIGHTPAREN", FIFE::Key::KP_RIGHTPAREN},
        {"KP_LEFTBRACE", FIFE::Key::KP_LEFTBRACE},
        {"KP_RIGHTBRACE", FIFE::Key::KP_RIGHTBRACE},
        {"KP_TAB", FIFE::Key::KP_TAB},
        {"KP_BACKSPACE", FIFE::Key::KP_BACKSPACE},
        {"KP_A", FIFE::Key::KP_A},
        {"KP_B", FIFE::Key::KP_B},
        {"KP_C", FIFE::Key::KP_C},
        {"KP_D", FIFE::Key::KP_D},
        {"KP_E", FIFE::Key::KP_E},
        {"KP_F", FIFE::Key::KP_F},
        {"KP_XOR", FIFE::Key::KP_XOR},
        {"KP_POWER", FIFE::Key::KP_POWER},
        {"KP_PERCENT", FIFE::Key::KP_PERCENT},
        {"KP_LESS", FIFE::Key::KP_LESS},
        {"KP_GREATER", FIFE::Key::KP_GREATER},
        {"KP_AMPERSAND", FIFE::Key::KP_AMPERSAND},
        {"KP_DBLAMPERSAND", FIFE::Key::KP_DBLAMPERSAND},
        {"KP_VERTICALBAR", FIFE::Key::KP_VERTICALBAR},
        {"KP_DBLVERTICALBAR", FIFE::Key::KP_DBLVERTICALBAR},
        {"KP_COLON", FIFE::Key::KP_COLON},
        {"KP_HASH", FIFE::Key::KP_HASH},
        {"KP_SPACE", FIFE::Key::KP_SPACE},
        {"KP_AT", FIFE::Key::KP_AT},
        {"KP_EXCLAM", FIFE::Key::KP_EXCLAM},
        {"KP_MEMSTORE", FIFE::Key::KP_MEMSTORE},
        {"KP_MEMRECALL", FIFE::Key::KP_MEMRECALL},
        {"KP_MEMCLEAR", FIFE::Key::KP_MEMCLEAR},
        {"KP_MEMADD", FIFE::Key::KP_MEMADD},
        {"KP_MEMSUBSTRACT", FIFE::Key::KP_MEMSUBSTRACT},
        {"KP_MEMMULTIPLY", FIFE::Key::KP_MEMMULTIPLY},
        {"KP_MEMDIVIDE", FIFE::Key::KP_MEMDIVIDE},
        {"KP_PLUSMINUS", FIFE::Key::KP_PLUSMINUS},
        {"KP_CLEAR", FIFE::Key::KP_CLEAR},
        {"KP_CLEARENTRY", FIFE::Key::KP_CLEARENTRY},
        {"KP_BINARY", FIFE::Key::KP_BINARY},
        {"KP_OCTAL", FIFE::Key::KP_OCTAL},
        {"KP_DECIMAL", FIFE::Key::KP_DECIMAL},
        {"KP_HEXADECIMAL", FIFE::Key::KP_HEXADECIMAL},

        {"LEFT_CONTROL", FIFE::Key::LEFT_CONTROL},
        {"LEFT_SHIFT", FIFE::Key::LEFT_SHIFT},
        {"LEFT_ALT", FIFE::Key::LEFT_ALT},
        {"LEFT_SUPER", FIFE::Key::LEFT_SUPER},
        {"RIGHT_CONTROL", FIFE::Key::RIGHT_CONTROL},
        {"RIGHT_SHIFT", FIFE::Key::RIGHT_SHIFT},
        {"RIGHT_ALT", FIFE::Key::RIGHT_ALT},
        {"RIGHT_SUPER", FIFE::Key::RIGHT_SUPER},

        {"ALT_GR", FIFE::Key::ALT_GR},

        {"AUDIO_NEXT", FIFE::Key::AUDIO_NEXT},
        {"AUDIO_PREV", FIFE::Key::AUDIO_PREV},
        {"AUDIO_STOP", FIFE::Key::AUDIO_STOP},
        {"AUDIO_PLAY", FIFE::Key::AUDIO_PLAY},
        {"AUDIO_MUTE", FIFE::Key::AUDIO_MUTE},
        {"MEDIASELECT", FIFE::Key::MEDIASELECT},
        {"WWW", FIFE::Key::WWW},
        {"MAIL", FIFE::Key::MAIL},
        {"CALCULATOR", FIFE::Key::CALCULATOR},
        {"COMPUTER", FIFE::Key::COMPUTER},
        {"AC_SEARCH", FIFE::Key::AC_SEARCH},
        {"AC_HOME", FIFE::Key::AC_HOME},
        {"AC_BACK", FIFE::Key::AC_BACK},
        {"AC_FORWARD", FIFE::Key::AC_FORWARD},
        {"AC_STOP", FIFE::Key::AC_STOP},
        {"AC_REFRESH", FIFE::Key::AC_REFRESH},
        {"AC_BOOKMARKS", FIFE::Key::AC_BOOKMARKS},

        {"BRIGHTNESS_DOWN", FIFE::Key::BRIGHTNESS_DOWN},
        {"BRIGHTNESS_UP", FIFE::Key::BRIGHTNESS_UP},
        {"DISPLAY_SWITCH", FIFE::Key::DISPLAY_SWITCH},
        {"ILLUM_TOGGLE", FIFE::Key::ILLUM_TOGGLE},
        {"ILLUM_DOWN", FIFE::Key::ILLUM_DOWN},
        {"ILLUM_UP", FIFE::Key::ILLUM_UP},
        {"EJECT", FIFE::Key::EJECT},
        {"SLEEP", FIFE::Key::SLEEP}
    });
}


