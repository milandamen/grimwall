#ifndef GRIMWALL_ATROUP_H
#define GRIMWALL_ATROUP_H


#include "../AUnit.h"

class ATroup : public AUnit {
private:
    int moveSpeed;
    int price;
public:
    ATroup(std::string name, int reach, int attackDelay, int moveSpeed, int power,
               int hitPoints, int visibility);
    virtual int getMoveSpeed() = 0;
    virtual int getPrice() = 0;
    virtual void doDamage(int power);
};


#endif //GRIMWALL_ATROUP_H
