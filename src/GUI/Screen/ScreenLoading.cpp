

#include <thread>
#include "ScreenLoading.h"

ScreenLoading::ScreenLoading(IGame *game, AGUIManager *manager)
        : GUI(manager), game(game)
{
    this->imgBg = manager->addImage("assets/gui/menubackground.png", 0, 0, 1024, 786);
    this->progressBar = manager->addContainer(1024-500-250, 500, 0, 20);
    this->progressBar->setBackgroundColor(0, 255, 0, 255);


}

ScreenLoading::~ScreenLoading() {
    delete this->imgBg;
}

void thread(ScreenLoading* self) {
    while(!self->tick());
}

void ScreenLoading::hasBecomeActive() {
    this->timer = 0;
    std::thread(thread, this).detach();
}

bool ScreenLoading::tick() {
    if(timer < duration) {
        timer++;

        int width = 500 / duration;
        this->progressBar->setWidth(width*timer);
        usleep(10000);
        return false;
    }

    this->game->setUI("Game");
    return true;
}
