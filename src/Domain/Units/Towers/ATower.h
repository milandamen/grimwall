#ifndef GRIMWALL_TOWER_H
#define GRIMWALL_TOWER_H

#include "../AUnit.h"


class ATower : public AUnit {
private:
    std::string id;
    int timeLastAttack {0};
public:
    ATower (std::string name, int reach, int attackDelay, int power, int hitPoints, int visibility);
    virtual std::string getId();
    virtual void setId(std::string id);
    virtual void setTimeLastAttack(int time);
    virtual int getTimeLastAttack();
};


#endif //GRIMWALL_TOWER_H
