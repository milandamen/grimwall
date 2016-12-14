#include "FIFEAudio.h"

FIFEAudio::FIFEAudio(FIFE::SoundClipManager* soundClipManager, FIFE::SoundManager* soundManager)
        : soundClipManager{soundClipManager}, soundManager{soundManager} {

    setVolume(100);

    soundEmitter = soundManager->createEmitter();

    FIFE::OggLoader* loader = new FIFE::OggLoader();

    FIFE::SoundClipPtr soundClip = soundClipManager->load("assets/sounds/intro.ogg", loader);
    std::string name = soundClip.get()->getName();
    soundEmitter->setSoundClip(soundClip);

    soundEmitter->play();
}

FIFEAudio::~FIFEAudio() {

}

void FIFEAudio::setVolume(int volume) {
    soundManager->setVolume(0.01 * volume);
}

void FIFEAudio::playAudio() {


}

void FIFEAudio::stopAudio() {

}

void FIFEAudio::playSound() {

}
