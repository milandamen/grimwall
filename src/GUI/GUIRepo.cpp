
#include "GUIRepo.h"

GUIRepo::GUIRepo(IGame* game)
{
    this->addGUI("MainMenu", new ScreenMainMenu(game, EngineFacade::engine()->createGUIManager()));
    this->addGUI("GameOver", new ScreenGameOver(game, EngineFacade::engine()->createGUIManager()));
    this->addGUI("Won", new ScreenWon(game, EngineFacade::engine()->createGUIManager()));
    this->addGUI("SelectHero", new ScreenSelectHero(game, EngineFacade::engine()->createGUIManager()));
    this->addGUI("SelectLevel", new ScreenSelectLevel(game, EngineFacade::engine()->createGUIManager()));
    this->addGUI("Options", new ScreenOptions(game, EngineFacade::engine()->createGUIManager()));
    this->addGUI("Pause", new ScreenPause(game, EngineFacade::engine()->createGUIManager()));
    this->addGUI("Help", new ScreenHelp(game, EngineFacade::engine()->createGUIManager()));
    this->addGUI("Credits", new ScreenCredits(game, EngineFacade::engine()->createGUIManager()));
    this->addGUI("Highscores", new ScreenHighscores(game, EngineFacade::engine()->createGUIManager()));
    this->addGUI("Game", new ScreenGame(game, EngineFacade::engine()->createGUIManager()));
    this->addGUI("Load", new ScreenLoad(game, EngineFacade::engine()->createGUIManager()));
}

GUIRepo::~GUIRepo()
{
    for(auto gui : this->guis)
    {
        delete gui.second;
    }
}

void GUIRepo::addGUI(std::string name, GUI *gui)
{
    this->guis[name] = gui;
}

GUI* GUIRepo::getGUI(std::string name)
{
    return this->guis[name];
}