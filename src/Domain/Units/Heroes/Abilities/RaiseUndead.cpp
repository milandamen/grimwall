#include "RaiseUndead.h"

RaiseUndead::RaiseUndead(vector<IUnit *> troups)
        :AAbility(50), troups{troups}
{

}

int RaiseUndead::execute() {
    for (size_t i = 0; i < this->troups.size(); ++i) {
        // TODO: Troup is alive
    }

    return 1;
}
