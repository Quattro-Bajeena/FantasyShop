#pragma once
#include "Item.h"
class Armor :
    public Item
{
private:
    int defence;
public:
    Armor(std::string name, float weight, float price, int defence);
    int GetDefence() const;
    void SetDefence(int new_defence);

    void Print(std::ostream& o) const override;
};

