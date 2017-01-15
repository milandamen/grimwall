#include "FIFEAudio.h"

FIFEAudio::FIFEAudio(FIFE::SoundClipManager* musicSoundClipManager, FIFE::SoundManager* musicSoundManager)
        : musicSoundClipManager{musicSoundClipManager}, musicSoundManager{musicSoundManager}{
    oggLoader = new FIFE::OggLoader();

    //Music
    musicSoundManager->init();

    musicMap = loadMusicMaps("assets/sounds/music/");
    effectMap = loadMusicMaps("assets/sounds/effects/");
}

FIFEAudio::~FIFEAudio() {
    releaseMap(musicMap);
    releaseMap(effectMap);
    delete musicMap;
    delete effectMap;
    delete oggLoader;
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
            emitter = musicSoundManager->createEmitter();
            emitter->setSoundClip(musicSoundClipManager->load(asset, oggLoader));
            map->insert(std::make_pair(strs[0], emitter));
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
    musicSoundManager->setVolume(0.01 * volume);
}

FIFE::SoundEmitter* FIFEAudio::getSoundEffect(std::string soundName) {
    return effectMap->at(soundName);
}

FIFE::SoundEmitter* FIFEAudio::getSoundClip(std::string soundName) {
    return musicMap->at(soundName);
}

void FIFEAudio::playMusic(std::string asset) {
    currentMusic = getSoundClip(asset);
    currentMusic->play();
}

void FIFEAudio::playSoundEffect(std::string asset) {
    currentEffect = getSoundEffect(asset);
    currentEffect->play();
}

void FIFEAudio::stopMusic() {
    if(currentMusic != nullptr){
        currentMusic->stop();
    }
}

void FIFEAudio::stopSoundEffect() {
    if(currentEffect != nullptr) {
        currentEffect->stop();
    }
}

void FIFEAudio::stopAllSound() {
    stopMusic();
    stopSoundEffect();
}












