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
    FIFE::SoundClipManager* musicSoundClipManager;
    FIFE::SoundManager* musicSoundManager;
    FIFE::SoundEmitter* musicSoundEmmiter;
    FIFE::SoundEmitter* effectSoundEmmiter;
    FIFE::OggLoader* oggLoader;



    std::map<std::string, std::string> *musicMap;
    std::map<std::string, std::string> *effectMap;

    std::map<std::string, std::string>* loadMusicMaps(std::string musicType);
public:
    FIFEAudio(FIFE::SoundClipManager* musicSoundClipManager, FIFE::SoundManager* musicSoundManager);
    ~FIFEAudio();

    void setVolume(int volume);
    void playMusic(std::string asset);
    void playSoundEffect(std::string asset);
    FIFE::SoundClipPtr getSoundEffect(std::string soundName);
    FIFE::SoundClipPtr getSoundClip(std::string soundName);
};


#endif //GRIMWALL_FIFEAUDIO_H
