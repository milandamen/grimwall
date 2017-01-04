#include "FIFEAudio.h"

FIFEAudio::FIFEAudio(FIFE::SoundClipManager* musicSoundClipManager, FIFE::SoundManager* musicSoundManager)
        : musicSoundClipManager{musicSoundClipManager}, musicSoundManager{musicSoundManager}{
    oggLoader = new FIFE::OggLoader();

    //Music
    musicSoundManager->init();

    musicMap = loadMusicMaps("assets/sounds/music");
    effectMap = loadMusicMaps("assets/sounds/effects");
}

FIFEAudio::~FIFEAudio() {
    delete oggLoader;
    delete musicMap;
    delete effectMap;
}

std::map<std::string, std::string>* FIFEAudio::loadMusicMaps(std::string musicType) {
    //load all music files, make clips and store them to the musicMap
    std::map<std::string, std::string> *map = new std::map<std::string, std::string>();

    DIR *pDIR = nullptr;
    dirent *entry = nullptr;
    const char* dirname = musicType.c_str();

    if((pDIR = opendir(dirname)) != nullptr){
        while((entry = readdir(pDIR)) != nullptr){
            std::string asset = musicType + entry->d_name;
            map->insert("AD", "BD");
        }
        closedir(pDIR);
    }

    return map;
}

void FIFEAudio::setVolume(int volume) {
    musicSoundManager->setVolume(0.01 * volume);
}

void FIFEAudio::playMusic(std::string asset) {
    musicSoundEmmiter = musicSoundManager->createEmitter();

    FIFE::SoundClipPtr soundClip = musicSoundClipManager->load(asset, oggLoader);
    musicSoundEmmiter->setSoundClip(soundClip);

    musicSoundEmmiter->play();
}

void FIFEAudio::playSoundEffect(std::string asset) {
    effectSoundEmmiter = musicSoundManager->createEmitter();

    FIFE::SoundClipPtr soundClip = musicSoundClipManager->load(asset, oggLoader);
    effectSoundEmmiter->setSoundClip(soundClip);

    effectSoundEmmiter->play();
}











