//
// Created by stephanromer on 1/16/17.
//

#ifndef GRIMWALL_LEVEL_H
#define GRIMWALL_LEVEL_H


class ILevel {
private:
    std::string map {""};
    int spawnHeroX {0};
    int spawnHeroY {0};
public:
    std::string getMap();
    int getSpawnHeroX();
    int getSpawnHeroY();
};


#endif //GRIMWALL_LEVEL_H
