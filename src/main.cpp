#include <iostream>
#include "Domain/Game.h"
#include "Domain/Units/Heroes/Horwen.h"

int main() {
    std::cout << "test" << std::endl; 
    
//    Game game;

    Horwen *hero = new Horwen();

    std::cout << hero->getAttackDelay() << std::endl;
    hero->activateRage();
    std::cout << "Rage activated!" << std::endl;
    std::cout << hero->getAttackDelay() << std::endl;




    return 0;
}