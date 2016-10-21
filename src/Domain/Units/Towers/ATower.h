#ifndef GRIMWALL_TOWER_H
#define GRIMWALL_TOWER_H

class ATower {
private:
    int doesDamage;
    int hitPoints;
public:
    virtual void shoot() = 0;
};


#endif //GRIMWALL_TOWER_H
