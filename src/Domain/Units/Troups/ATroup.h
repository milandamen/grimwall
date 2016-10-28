#ifndef GRIMWALL_ATROUP_H
#define GRIMWALL_ATROUP_H

#include <string>

class ATroup {
private:
    std::string name;
    int moveSpeed;
    int price;
    int range;
    int attackDelay;
    int power;
    int hitPoints;
public:
    ATroup(std::string name, int moveSpeed, int price, int range, int attackDelay, int power, int hitPoints);
    ~ATroup();
    virtual int getMoveSpeed() = 0;
    virtual int getPrice() = 0;
    virtual int getRange() = 0;
    virtual int getAttackDelay = 0;
    virtual int getPower() = 0;
    virtual int getHitpoints() = 0;
    virtual bool isAlive() = 0;
    virtual void doDamage(int power);
};


#endif //GRIMWALL_ATROUP_H
