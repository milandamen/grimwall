#include "SmokeBomb.h"
#include "../../Buff/SmokeBombBuff.h"

SmokeBomb::SmokeBomb(std::vector<IUnit*> towers)
        : AAbility(40), towers{towers}
{
    
}

int SmokeBomb::execute()
{

    for(size_t i = 0; i < towers.size(); i++)
    {
        towers.at(i) = new SmokeBombBuff(towers.at(i), 2);
    }

    return 1;

}

