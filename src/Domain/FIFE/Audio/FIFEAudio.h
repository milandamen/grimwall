#ifndef GRIMWALL_FIFEAUDIO_H
#define GRIMWALL_FIFEAUDIO_H

#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<string.h>
#include<fstream>
#include<dirent.h>

#include <audio/soundclipmanager.h>
#include <audio/soundmanager.h>
#include <audio/soundclip.h>
#include <audio/soundemitter.h>
#include <loaders/native/audio/ogg_loader.h>

class FIFEAudio {
private:
    FIFE::SoundClipManager* musicSoundClipManager;
    FIFE::SoundManager* musicSoundManager;
    FIFE::SoundEmitter* musicSoundEmmiter;
    FIFE::OggLoader* oggLoader;

    FIFE::SoundEmitter* effectSoundEmmiter;

    std::map<std::string, std::string> *musicMap;
    std::map<std::string, std::string> *effectMap;

    //void loadMusicMaps(std::map<std::string, std::string>&, std::string musicType);
    std::map<std::string, std::string>* loadMusicMaps(std::string musicType);
public:
    FIFEAudio(FIFE::SoundClipManager* musicSoundClipManager, FIFE::SoundManager* musicSoundManager);
    ~FIFEAudio();

    //set volume, enable/disable music
    void setVolume(int volume);
    void playMusic(std::string asset);
    void playSoundEffect(std::string asset);
};


#endif //GRIMWALL_FIFEAUDIO_H
