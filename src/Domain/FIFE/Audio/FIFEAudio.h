#ifndef GRIMWALL_FIFEAUDIO_H
#define GRIMWALL_FIFEAUDIO_H

#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<string>
#include<fstream>
#include<dirent.h>

#include <audio/soundclipmanager.h>
#include <audio/soundmanager.h>
#include <audio/soundclip.h>
#include <audio/soundemitter.h>
#include <loaders/native/audio/ogg_loader.h>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>

namespace fs = boost::filesystem;

class FIFEAudio {
private:
    int volume {100};

    FIFE::SoundClipManager* musicSoundClipManager;
    FIFE::SoundManager* musicSoundManager;
    FIFE::SoundEmitter* emitter;
    FIFE::SoundEmitter* currentMusic;
    FIFE::SoundEmitter* currentEffect;
    FIFE::OggLoader* oggLoader;

    std::map<std::string, FIFE::SoundEmitter*> *musicMap;
    std::map<std::string, FIFE::SoundEmitter*> *effectMap;

    std::map<std::string, FIFE::SoundEmitter*>* loadMusicMaps(std::string musicType);
public:
    FIFEAudio(FIFE::SoundClipManager* musicSoundClipManager, FIFE::SoundManager* musicSoundManager);
    ~FIFEAudio();

    void setVolume(int volume);
    int getVolume();
    void playMusic(std::string asset);
    void playSoundEffect(std::string asset);
    void stopMusic();
    void stopSoundEffect();
    void stopAllSound();
    void releaseMap(std::map<std::string, FIFE::SoundEmitter *> *map);
    FIFE::SoundEmitter* getSoundEffect(std::string soundName);
    FIFE::SoundEmitter* getSoundClip(std::string soundName);
};


#endif //GRIMWALL_FIFEAUDIO_H
