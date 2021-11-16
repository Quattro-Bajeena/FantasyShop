#include "Item.h"

Item::Item(std::string name, float weight, float price)
	:name(name), weight(weight), price(price)
{
}

std::string Item::GetName() const
{
	return name;
}

float Item::GetWeight() const
{
	return weight;
}

int Item::GetPrice() const
{
	return price;
}

void Item::SetName(std::string new_name)
{
	name = new_name;
}

void Item::SetWeight(float new_weight)
{
	weight = new_weight;
}

void Item::SetPrice(int new_price)
{
	price = new_price;
}

std::ostream& operator<<(std::ostream& o, const Item& item)
{
	item.Print(o);
	return o;
}
