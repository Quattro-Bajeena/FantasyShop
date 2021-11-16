#include "Weapon.h"

Weapon::Weapon(std::string name, float weight, float price, int attack)
	:Item(name, weight, price), attack(attack)
{
}

int Weapon::GetAttack() const
{
	return attack;
}

void Weapon::SetAttack(int new_attack)
{
	attack = new_attack;
}

void Weapon::Print(std::ostream& o) const
{

	o << "Name: " << name << "\n";
	o << "Weight: " << weight << "\n";
	o << "Price: " << price << "\n";
	o << "Attack: " << attack << "\n";
}
