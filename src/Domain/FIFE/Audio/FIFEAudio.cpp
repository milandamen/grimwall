#include "FIFEAudio.h"

FIFEAudio::FIFEAudio(FIFE::SoundClipManager* musicSoundClipManager, FIFE::SoundManager* musicSoundManager)
        : musicSoundClipManager{musicSoundClipManager}, musicSoundManager{musicSoundManager}{
    this->oggLoader = new FIFE::OggLoader();

    //Music
    this->musicSoundManager->init();

    this->musicMap = loadMusicMaps("assets/sounds/music/");
    this->effectMap = loadMusicMaps("assets/sounds/effects/");
}

FIFEAudio::~FIFEAudio() {
    this->releaseMap(musicMap);
    this->releaseMap(effectMap);
    delete this->musicMap;
    delete this->effectMap;
    delete this->oggLoader;
}

std::map<std::string, FIFE::SoundEmitter*>* FIFEAudio::loadMusicMaps(std::string musicType) {

    std::map<std::string, FIFE::SoundEmitter*> *map = new std::map<std::string, FIFE::SoundEmitter*>();

    fs::path p(musicType);
    for (auto i = fs::directory_iterator(p); i != fs::directory_iterator(); i++)
    {
        if (!is_directory(i->path()))
        {
            std::string asset = musicType + i->path().filename().string();

            std::vector<std::string> strs;
            boost::split(strs, i->path().filename().string(), boost::is_any_of("."));
            this->emitter = this->musicSoundManager->createEmitter();
            this->emitter->setSoundClip(this->musicSoundClipManager->load(asset, this->oggLoader));
            map->insert(std::make_pair(strs[0], this->emitter));
        }
    }

    return map;
}

void FIFEAudio::releaseMap(std::map<std::string, FIFE::SoundEmitter *> *map) {
    if(map->size() != 0){
        std::map<std::string, FIFE::SoundEmitter*>::iterator it;
        for ( it = map->begin(); it != map->end(); it++ ){
            it->second->reset(true);
        }
    }
}

void FIFEAudio::setVolume(int volume) {
    this->volume = volume;
    this->musicSoundManager->setVolume(0.01 * this->volume);
}

int FIFEAudio::getVolume() {
    return this->volume;
}

FIFE::SoundEmitter* FIFEAudio::getSoundEffect(std::string soundName) {
    return this->effectMap->at(soundName);
}

FIFE::SoundEmitter* FIFEAudio::getSoundClip(std::string soundName) {
    return this->musicMap->at(soundName);
}

void FIFEAudio::playMusic(std::string asset) {
    if(this->currentMusic != getSoundClip(asset)){
        this->currentMusic = getSoundClip(asset);
        this->currentMusic->play();
    }
}

void FIFEAudio::playSoundEffect(std::string asset) {
    this->currentEffect = getSoundEffect(asset);
    this->currentEffect->play();
}

void FIFEAudio::stopMusic() {
    if(this->currentMusic != nullptr){
        this->currentMusic->stop();
    }
}

void FIFEAudio::stopSoundEffect() {
    if(this->currentEffect != nullptr) {
        this->currentEffect->stop();
    }
}

void FIFEAudio::stopAllSound() {
    this->stopMusic();
    this->stopSoundEffect();
}












