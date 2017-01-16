
#include "FIFEChan.h"

FIFEChan::FIFEChan(FIFE::Engine* engine)
{
    this->engine = engine;
    this->guimanager = new FIFE::FifechanManager();
}

FIFEChan::~FIFEChan()
{
}

void FIFEChan::init()
{
    this->guimanager->setDefaultFont(
            this->engine->getSettings().getDefaultFontPath(),
            this->engine->getSettings().getDefaultFontSize(),
            this->engine->getSettings().getDefaultFontGlyphs()
    );

    this->guimanager->init(
            this->engine->getRenderBackend()->getName(),
            this->engine->getRenderBackend()->getScreenWidth(),
            this->engine->getRenderBackend()->getScreenHeight()
    );

    this->engine->setGuiManager(this->guimanager);
}

FIFE::FifechanManager* FIFEChan::getGuiManager()
{
    return this->guimanager;
}