#include "Game.h"

Game::Game()
{
    EngineFacade::setEngine("FIFE", this);
    EngineFacade::engine()->setRenderBackend("OpenGL");
    EngineFacade::engine()->setFPSLimit(60);
    EngineFacade::engine()->init();
}

Game::~Game() {
    for(auto level : this->levels)
        delete level.second;

    delete this->hero;
    this->deleteTowers();
}

void Game::init()
{
    this->guirepo = new GUIRepo(this);
    this->setUI("MainMenu");

    this->initInput();

    ILevel* l = new Level1();
    this->currentLevel = l;
    this->levels[l->getName()] = l;
    l = new Level2();
    this->levels[l->getName()] = l;
    l = new Level3();
    this->levels[l->getName()] = l;

    this->hero = new UnitManager<AHero>(new Dralas());
    this->hero->getBase()->addAbility(new DeathStrike(this->hero));

    setSaveGameManager(new SaveGameManager {"TEXT"});

    this->towerManager.setTowers(this->getTowers());
    this->towerManager.setUnits(this->troupManager.getTroups());
    this->towerManager.setHero(hero);

    this->troupManager.setTowers(this->getTowers());

    // Game loop
    this->curTime = 0;
    this->lastTime = 0;
    this->paused = true;

    while (this->running)
    {
        updateFPS();

        // Check if we are in pause state
        if(!this->paused) {
            this->tick();
        }

        // Render a frame
        EngineFacade::engine()->render();
        this->curTime = EngineFacade::engine()->getTime();
    }

    EngineFacade::destroy();
    delete this->keyboardMapper;
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
    // Run an engine tick for userland code
    EngineFacade::engine()->tick();
    if (this->speedHackEnabled) {
        for (int i {0}; i < 3; i++) {
            EngineFacade::engine()->tick();
        }
    }
    
    updateLocation(this->hero, this->hero->getName());


    this->towerManager.tick();

    for(unsigned i = 0; i < this->troupManager.getTroups()->size(); ++i){
        updateLocation(this->troupManager.getTroups()->at(i), this->troupManager.getTroups()->at(i)->getName());
    }

    this->troupManager.tick();

    if(++this->scoreCount % 60 == 0) {
        this->scoreCount = 0;
        this->score--;
    }

    if (this->hero->getHitPoints() <= 0){
        this->lose();
    } else if (this->towers.size() <= 0) {
        this->win();
    }

    this->hero->tick();

    EngineFacade::engine()->drawBox(
            troupManager.sStartX,
            troupManager.sStartY,
            troupManager.sEndX,
            troupManager.sEndY);
}

void Game::win() {
    this->paused = true;
    this->setUI("Won");
}

void Game::lose() {
    this->paused = true;
    this->setUI("GameOver");

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

void Game::loadLevel(std::string levelName)
{
    this->troupManager.reset();
    this->currentLevel = this->levels[levelName];
    this->setMap(this->currentLevel->getMap());

    EngineFacade::engine()->enableCamera();

    std::vector<int> spawnPos = EngineFacade::engine()->getHerospawnPoint();
    EngineFacade::engine()->createInstance(this->getHero()->getName(), this->getHero()->getName(), spawnPos.at(0), spawnPos.at(1));
}

ILevel* Game::getCurrentLevel()
{
    return this->currentLevel;
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
        // Fetch the hero and the level and put it into the save file.
        this->currentSave->lastUsedHero = this->getHero()->getName();
        this->currentSave->lastUnlockedLevel = this->currentLevel->getName();
        this->currentSave->score = std::to_string(this->getCurrentScore());

        this->currentSave->save();
    }
}

void Game::setSpeedHack(bool enabled)
{
    this->speedHackEnabled = enabled;
    this->towerManager.setSpeedHack(enabled);
}
