#pragma once
#include "Item.h"
class Weapon :
    public Item
{
private:
    int attack;

public:
    Weapon(std::string name, float weight, float price, int attack);
    int GetAttack() const;
    void SetAttack(int new_attack);

    void Print(std::ostream& o) const override;
};

