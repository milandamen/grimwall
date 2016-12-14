#include "FIFEAudio.h"

FIFEAudio::FIFEAudio(FIFE::SoundClipManager* soundClipManager, FIFE::SoundManager* soundManager)
        : soundClipManager{soundClipManager}, soundManager{soundManager}, canPlay{false} {
    oggLoader = new FIFE::OggLoader();
    soundManager->init();
    soundEmitter = soundManager->createEmitter();
}

FIFEAudio::~FIFEAudio() {
    delete oggLoader;
}

void FIFEAudio::setVolume(int volume) {
    soundManager->setVolume(0.01 * volume);
}

void FIFEAudio::playMusic() {
    if(canPlay)
        soundEmitter->play();
}

void FIFEAudio::disableMusic() {
    canPlay = false;
}

void FIFEAudio::enableMusic() {
    canPlay = true;
    playMusic();
}

void FIFEAudio::setMusic(std::string asset) {
    FIFE::SoundClipPtr soundClip = soundClipManager->load(asset, oggLoader);
    soundEmitter->setSoundClip(soundClip);
}









