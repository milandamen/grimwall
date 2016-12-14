//
// Created by stephanromer on 12/14/16.
//

#include "ScreenGame.h"


ScreenGame::ScreenGame(IGame* game, AGUIManager* manager)
        : game(game), GUI(manager)
{}

ScreenGame::~ScreenGame()
{}