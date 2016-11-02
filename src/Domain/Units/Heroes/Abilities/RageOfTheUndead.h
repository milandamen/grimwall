#ifndef GRIMWALL_RAGEOFTHEUNDEAD_H
#define GRIMWALL_RAGEOFTHEUNDEAD_H

#include <iostream>
#include <vector>
#include "../AAbility.h"
#include "../AHero.h"

using std::vector;

class RageOfTheUndead : public AAbility {
private:
    vector<IUnit*> troups;
public:
    RageOfTheUndead(vector<IUnit*> troups);
    int execute();
};


#endif //GRIMWALL_RAGEOFTHEUNDEAD_H
