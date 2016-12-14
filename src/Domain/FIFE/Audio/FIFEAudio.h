#ifndef GRIMWALL_FIFEAUDIO_H
#define GRIMWALL_FIFEAUDIO_H

#include <audio/soundclipmanager.h>
#include <audio/soundmanager.h>
#include <audio/soundclip.h>
#include <audio/soundemitter.h>
#include <loaders/native/audio/ogg_loader.h>

class FIFEAudio {
private:
    FIFE::SoundClipManager* soundClipManager;
    FIFE::SoundManager* soundManager;
    FIFE::SoundEmitter* soundEmitter;
    FIFE::OggLoader* oggLoader;
public:
    FIFEAudio(FIFE::SoundClipManager* soundClipManager, FIFE::SoundManager* soundManager);
    ~FIFEAudio();

    //set volume, enable/disable music
    void setVolume(int volume);
};


#endif //GRIMWALL_FIFEAUDIO_H
