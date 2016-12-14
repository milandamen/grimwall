#ifndef GRIMWALL_TOWER_H
#define GRIMWALL_TOWER_H

#include "../AUnit.h"


class ATower : public AUnit {
private:
    std::string id;
    int timeLastAttack {-23};
public:
    ATower (std::string name, int reach, int attackDelay, int power, int hitPoints, int visibility);
    virtual void doDamage(int power);
    virtual std::string getId();
    virtual void setId(std::string id);
    virtual void setTimeLastAttack(int time);
    virtual int getTimeLastAttack();
};


#endif //GRIMWALL_TOWER_H
