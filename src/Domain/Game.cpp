#include "Game.h"

#include "Units/Heroes/Abilities/DeathStrike.h"

Game::Game()
{
    EngineFacade::setEngine("FIFE", this);
    EngineFacade::engine()->setRenderBackend("OpenGL");
    EngineFacade::engine()->setFPSLimit(60);
    EngineFacade::engine()->init();

    this->guirepo = new GUIRepo(this);

    EngineFacade::engine()->setActiveGUIManager(this->guirepo->getGUI("MainMenu")->getGuiManager());

    this->initInput();

    this->hero = new UnitManager<AHero>(new Dralas());
    this->hero->getBase()->addAbility(new DeathStrike(this->hero));

    setSaveGameManager(new SaveGameManager {"TEXT"});

    this->towerManager.setTowers(this->getTowers());
    this->towerManager.setHero(hero);

    // Game loop
    this->curTime = 0;
    this->lastTime = 0;
    this->paused = true;

    while (this->running)
    {
        updateFPS();

        // Check if we are in pause state
        if(!this->paused) {
            // Run an engine tick for userland code
            EngineFacade::engine()->tick();
            this->tick();
        }

        // Render a frame
        EngineFacade::engine()->render();
        this->curTime = EngineFacade::engine()->getTime();
    }
    
    EngineFacade::destroy();
    delete this->keyboardMapper;
}

Game::~Game() {
    delete this->hero;
    this->deleteTowers();
}

void Game::setMap(std::string path)
{
    EngineFacade::engine()->loadMap(path);
    this->loadTowers();
}

int Game::getCurrentScore() {
    return this->score;
}

bool Game::isPaused()
{
    return this->paused;
}

void Game::setPaused(bool paused)
{
    this->paused = paused;
}

void Game::setHero(AHero *hero)
{
    if(this->hero != nullptr) {
        delete this->hero;
    }

    this->hero = new UnitManager<AHero>(hero);
}

void Game::setUI(std::string name)
{
    if(this->activeGUI != nullptr) {
        this->activeGUI->hasBecomeInactive();
    }

    GUI *gui = this->guirepo->getGUI(name);
    if (gui != nullptr) {
        this->activeGUI = gui;
        gui->hasBecomeActive();
        EngineFacade::engine()->setActiveGUIManager(gui->getGuiManager());
    }
}

void Game::tick() {
    updateLocation(this->hero, this->hero->getName());
    this->towerManager.tick(curTime);

    if (this->hero->getHitPoints() <= 0){
        this->lose();
    }
    else if (this->towers.size() <= 0){
        this->win();
    }

    this->hero->tick();
}

void Game::win() {
    this->paused = true;
    EngineFacade::engine()->setActiveGUIManager(this->guirepo->getGUI("Won")->getGuiManager());
}

void Game::lose() {
    this->paused = true;
    EngineFacade::engine()->setActiveGUIManager(this->guirepo->getGUI("GameOver")->getGuiManager());

}

UnitManager<AHero>* Game::getHero() {
    return this->hero;
}

void Game::quit()
{
    this->running = false;
}

void Game::initInput()
{
    this->keyboardMapper = new KeyboardMapper(this);
}

void Game::updateFPS()
{
    // Update FPS reading approx. every second
    if ((this->curTime > 0) && (this->curTime - this->lastTime >= 1000))
    {
        // Create Title + FPS string
        std::ostringstream oss;
        oss << "Grimwall [FPS: " << EngineFacade::engine()->getFPS() << "]";
        
        // Show FPS in windows title
        EngineFacade::engine()->setWindowTitle(oss.str());
        
        // Update the last time FPS was calculated
        this->lastTime = EngineFacade::engine()->getTime();
    }
}

void Game::loadTowers()
{
    this->towers = EngineFacade::engine()->loadTowers();
}

void Game::deleteTowers()
{
    for (unsigned int i = 0; i < this->towers.size(); ++i)
    {
        delete this->towers.at(i);
    }
    this->towers.clear();
}


TroupManager* Game::getTroupManager() {
    return &this->troupManager;
}

std::vector<UnitManager<ATower> *>* Game::getTowers() {
    return &this->towers;

}

ISaveGameManager* Game::getSaveGameManager()
{
    return this->saveGameManager;
}

void Game::setSaveGameManager(ISaveGameManager* saveGameManager)
{
    this->saveGameManager = saveGameManager;
}

void Game::loadGame(std::string fileName){
    SaveGame* temp = this->saveGameManager->load(fileName);
    if(temp == nullptr){
        temp = this->saveGameManager->create(fileName);
    }

    this->currentSave = temp;
}

void Game::saveGame(){
    if(currentSave != nullptr){

        this->currentSave->lastUsedHero = this->getHero()->getName();
        this->currentSave->save();
    }
}