#pragma once
#include <iostream>
#include <string>

class Item
{
protected:
	std::string name;
	float weight;
	int price;
public:
	Item(std::string name, float weight, float price);
	std::string GetName() const;
	float GetWeight() const;
	int GetPrice() const;

	void SetName(std::string new_name);
	void SetWeight(float new_weight);
	void SetPrice(int new_price);

	virtual void Modify();

	virtual void Print(std::ostream& o) const = 0;
	friend std::ostream& operator << (std::ostream& o, const Item& item);
};

