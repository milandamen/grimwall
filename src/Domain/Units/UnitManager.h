#ifndef GRIMWALL_UNITMANAGER_H
#define GRIMWALL_UNITMANAGER_H

#include "IUnit.h"

class UnitManager : public IUnit {
private:
    IUnit* unit;
public:
    UnitManager(IUnit* unit);
    ~UnitManager();
    std::string getName() override;
    int getReach() override;
    int getAttackDelay() override;
    int getPower() override;
    int getHitPoints() override;
    int getSpeed() override;
    int getVisibility() override;
    void doDamage(int power) override;

    double getX() override;
    void setX(double x) override;
    double getY() override;
    void setY(double y) override;

    IUnit* getUnit();

    template <typename Decorator>
    void decorate(Decorator* decorator) {
        this->unit = decorator;
    };
};


#endif //GRIMWALL_UNITMANAGER_H
