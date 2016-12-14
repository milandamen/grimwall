#include "FIFEAudio.h"

FIFEAudio::FIFEAudio(FIFE::SoundClipManager* soundClipManager, FIFE::SoundManager* soundManager)
        : soundClipManager{soundClipManager}, soundManager{soundManager} {
    oggLoader = new FIFE::OggLoader();

    setVolume(100);

    soundEmitter = soundManager->createEmitter();

    FIFE::SoundClipPtr soundClip = soundClipManager->load("assets/sounds/intro.ogg", oggLoader);

    soundEmitter->setSoundClip(soundClip);

    soundEmitter->play();
}

FIFEAudio::~FIFEAudio() {
    delete oggLoader;
}

void FIFEAudio::setVolume(int volume) {
    soundManager->setVolume(0.01 * volume);
}


