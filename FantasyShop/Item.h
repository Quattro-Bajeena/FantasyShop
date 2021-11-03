#pragma once
#include <iostream>

class Item
{
private:
	std::string name;
	float weight;
	int price;
public:
	Item(std::string name, float weight, float price);
	virtual std::string GetName() const = 0;
	virtual float GetWeight() const = 0;
	virtual int GetPrice() const = 0;
};

