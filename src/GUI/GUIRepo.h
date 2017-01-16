
#ifndef GRIMWALL_GUIREPO_H
#define GRIMWALL_GUIREPO_H

#include <map>
#include <string>
#include "GUI.h"

#include "../GUI/Screen/ScreenMainMenu.h"
#include "../GUI/Screen/ScreenSelectHero.h"
#include "../GUI/Screen/ScreenSelectLevel.h"
#include "../GUI/Screen/ScreenGameOver.h"
#include "../GUI/Screen/ScreenWon.h"
#include "../GUI/Screen/ScreenOptions.h"
#include "../GUI/Screen/ScreenPause.h"
#include "../GUI/Screen/ScreenHelp.h"
#include "../GUI/Screen/ScreenCredits.h"
#include "../GUI/Screen/ScreenHighscores.h"
#include "../GUI/Screen/ScreenGame.h"
#include "../GUI/Screen/ScreenLoad.h"

class GUIRepo {

private:
    std::map<std::string, GUI*> guis;

public:
    GUIRepo(IGame* game);
    ~GUIRepo();

    void addGUI(std::string name, GUI* gui);
    GUI* getGUI(std::string name);
};


#endif //GRIMWALL_GUIREPO_H
