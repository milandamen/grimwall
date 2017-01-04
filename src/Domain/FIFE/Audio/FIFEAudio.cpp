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
    delete oggLoader;
    delete musicMap;
    delete effectMap;
}

std::map<std::string, std::string>* FIFEAudio::loadMusicMaps(std::string musicType) {
    std::map<std::string, std::string> *map = new std::map<std::string, std::string>();

    fs::path p(musicType);
    for (auto i = fs::directory_iterator(p); i != fs::directory_iterator(); i++)
    {
        if (!is_directory(i->path())) //we eliminate directories in a list
        {
            std::cout << i->path().filename().string() << std::endl;
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












