#include "Manager.h"

void Manager::AddItem(Item* item)
{
	items.push_back(item);
}

int Suma(const Manager& manager)
{
	int sum = 0;
	for (auto item : manager.items) {
		sum += item->GetPrice();
	}
	return sum;
}
