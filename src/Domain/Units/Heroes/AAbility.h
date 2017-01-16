#ifndef GRIMWALL_IABILITY_H
#define GRIMWALL_IABILITY_H

#include <string>

class AAbility{
private:
    std::string name;
    int cost;
public:
    AAbility(std::string name, int cost);
    virtual ~AAbility() {};
    std::string getName();
    // return the reducing amount of energy
    int getCost();
    virtual int execute() = 0;
};

#endif