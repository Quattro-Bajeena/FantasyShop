#pragma once
#include <vector>
#include "Item.h"

class Manager
{
private:
	std::vector<Item*> items;
public:
	void AddItem(Item* item);
	friend int Suma(const Manager& manager);

};

int Suma(const Manager& manager);