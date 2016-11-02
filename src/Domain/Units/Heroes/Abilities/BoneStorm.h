#ifndef GRIMWALL_BONESTORM_H
#define GRIMWALL_BONESTORM_H

#include <iostream>
#include <vector>
#include "../AAbility.h"
#include "../../Towers/ATower.h"

using std::vector;

class BoneStorm : public AAbility {
private:
    vector<IUnit*> towers;
public:
    BoneStorm(vector<IUnit*> towers);
    int execute();
};


#endif //GRIMWALL_BONESTORM_H
