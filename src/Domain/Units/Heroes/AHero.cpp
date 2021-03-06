
#include "AHero.h"

AHero::AHero(std::string name, int reach, int attackDelay, int moveSpeed, int power, int hitPoints, int visibility)
        : AUnit(name, reach, attackDelay, power, hitPoints, moveSpeed, visibility)
{

}

AHero::~AHero() {
    for (auto& ability : this->abilities) {
        delete ability;
    }

    this->abilities.clear();
}

std::string AHero::getWeapon() {
    return this->weapon;
}

bool AHero::executeAbility(unsigned int number) {
    if (number < this->abilities.size() && number >= 0){
        if (this->abilities[number]->getCost() <= this->mana) {
            if (!this->infMana) {
                this->mana -= this->abilities[number]->getCost();
            }
            
            this->abilities[number]->execute();

            this->updateStatsListener();
            return true;
        }
    }

    return false;
}

void AHero::addAbility(AAbility *ability) {
    this->abilities.push_back(ability);
}

AAbility* AHero::getAbility(unsigned int number) {
    if (number < this->abilities.size() && number >= 0)
        return this->abilities[number];

    return nullptr;
}

int AHero::getMana() {
    return this->mana;
}

bool AHero::summon(){
    if (this->mana >= 55) {
        if (!this->infMana) {
            this->mana -= 55;
        }
        return true;
    }
    else {
        return false;
    }
}

void AHero::setInfMana(bool infMana)
{
    this->infMana = infMana;
}

void AHero::tick() {
    AUnit::tick();

    this->manaRegenTimeout--;
    if (this->manaRegenTimeout == 0) {
        this->manaRegenTimeout = 20;

        if (this->mana < 100) {
            this->mana++;
            this->updateStatsListener();
        }
    }
}
