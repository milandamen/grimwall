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

    delete musicMap;
    delete effectMap;
    delete oggLoader;
}

std::map<std::string, std::string>* FIFEAudio::loadMusicMaps(std::string musicType) {
    std::map<std::string, std::string> *map = new std::map<std::string, std::string>();

    fs::path p(musicType);
    for (auto i = fs::directory_iterator(p); i != fs::directory_iterator(); i++)
    {
        if (!is_directory(i->path()))
        {
            std::string asset = musicType + i->path().filename().string();

            std::vector<std::string> strs;
            boost::split(strs, i->path().filename().string(), boost::is_any_of("."));

            map->insert(std::make_pair(strs[0], asset));
        }
    }

    return map;
}

void FIFEAudio::setVolume(int volume) {
    musicSoundManager->setVolume(0.01 * volume);
}

FIFE::SoundClipPtr FIFEAudio::getSoundEffect(std::string soundName) {
    return musicSoundClipManager->load(effectMap->at(soundName), oggLoader);
}

FIFE::SoundClipPtr FIFEAudio::getSoundClip(std::string soundName) {
    return musicSoundClipManager->load(musicMap->at(soundName), oggLoader);
}

void FIFEAudio::playMusic(std::string asset) {
    musicSoundEmmiter = musicSoundManager->createEmitter();

    musicSoundEmmiter->setSoundClip(getSoundClip(asset));

    musicSoundEmmiter->play();
}

void FIFEAudio::playSoundEffect(std::string asset) {
    effectSoundEmmiter = musicSoundManager->createEmitter();

    effectSoundEmmiter->setSoundClip(getSoundEffect(asset));

    effectSoundEmmiter->play();
}












