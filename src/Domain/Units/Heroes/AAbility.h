#ifndef GRIMWALL_IABILITY_H
#define GRIMWALL_IABILITY_H

class AAbility{
private:
    int cost;
public:
    AAbility(int cost);
    ~AAbility();
    // return the reducing amount of energy???
    int getCost();
    virtual int execute() = 0;
};

#endif