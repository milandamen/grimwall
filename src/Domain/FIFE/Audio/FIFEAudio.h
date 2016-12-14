

#ifndef GRIMWALL_FIFEAUDIO_H
#define GRIMWALL_FIFEAUDIO_H

#include <audio/soundclipmanager.h>
#include <audio/soundmanager.h>
#include <audio/fife_openal.h>
#include <audio/soundclip.h>

#include <audio/soundconfig.h>
#include <audio/sounddecoder.h>
#include <audio/soundemitter.h>
#include <loaders/native/audio/ogg_loader.h>
#include "util/resource/resource.h"


class FIFEAudio {
private:
    FIFE::SoundClipManager* soundClipManager;
    FIFE::SoundManager* soundManager;
    FIFE::SoundEmitter* soundEmitter;
public:
    FIFEAudio(FIFE::SoundClipManager* soundClipManager, FIFE::SoundManager* soundManager);
    ~FIFEAudio();

    //volume, enable/disable music

    void init();
    static void playAudio();
    static void stopAudio();
    static void playSound();
    void setVolume(int volume);
};


#endif //GRIMWALL_FIFEAUDIO_H
