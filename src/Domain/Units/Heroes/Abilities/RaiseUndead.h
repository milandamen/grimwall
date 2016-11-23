#ifndef GRIMWALL_RAISEUNDEAD_H
#define GRIMWALL_RAISEUNDEAD_H

#include <iostream>
#include <vector>
#include "../AAbility.h"
#include "../../IUnit.h"

using std::vector;

class RaiseUndead : public AAbility {
private:
    vector<IUnit*> troups;
public:
    RaiseUndead(vector<IUnit*> troups);
    int execute();
};


#endif //GRIMWALL_RAISEUNDEAD_H
