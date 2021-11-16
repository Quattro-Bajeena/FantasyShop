#include "Armor.h"

Armor::Armor(std::string name, float weight, float price, int defence)
	:Item(name, weight, price), defence(defence)
{
}

int Armor::GetDefence() const
{
	return defence;
}

void Armor::SetDefence(int new_defence)
{
	defence = new_defence;
}

void Armor::Print(std::ostream& o) const
{
	o << "Name: " << name << "\n";
	o << "Weight: " << weight << "\n";
	o << "Price: " << price << "\n";
	o << "Defence: " << defence << "\n";
}
