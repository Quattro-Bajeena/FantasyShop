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

void Item::Modify()
{
    /*std::cout << "Curent statistics:\n";
    Print(std::cout);
    std::cout << "1. Modify name\n";
    std::cout << "2. Modify weight\n";
    std::cout << "3. Modify price\n";
    std::cout << "4. Modify attack\n";

    std::string pickedOption = "";

    while (!(pickedOption == "1" || pickedOption == "2" || pickedOption == "3" || pickedOption == "4")) {
        std::cin >> pickedOption;
        bool correctValue = false;

        if (pickedOption == "1") {
            std::cout << "Enter new name: ";
            std::string name;
            std::cin >> name;
            std::cout << "New name of " << weapon.GetName() << " is " << name << "\n";
            weapon.SetName(name);
        }
        else if (pickedOption == "2") {
            std::cout << "Enter new weight: ";
            float weight;
            std::string weightStr;
            correctValue = false;
            while (correctValue == false) {
                std::cin >> weightStr;
                try {
                    weight = std::stof(weightStr);
                    correctValue = true;
                }
                catch (std::invalid_argument ex) {
                    correctValue = false;
                    std::cout << "Incorect value\n";
                }
            }

            std::cout << "Old weight: " << weapon.GetWeight() << " new weight: " << weight << "\n";
            weapon.SetWeight(weight);
        }
        else if (pickedOption == "3") {
            std::cout << "Enter new price: ";
            int price;
            std::string priceStr;
            correctValue = false;
            while (correctValue == false) {
                std::cin >> priceStr;
                try {
                    price = std::stoi(priceStr);
                    correctValue = true;
                }
                catch (std::invalid_argument ex) {
                    correctValue = false;
                    std::cout << "Incorect value\n";
                }
            }
            std::cin >> price;
            std::cout << "Old price: " << weapon.GetPrice() << " new price: " << price << "\n";
            weapon.SetPrice(price);
        }
        else if (pickedOption == "4") {
            std::cout << "Enter new attack value: ";
            int attack;
            std::string attackStr;
            correctValue = false;
            while (correctValue == false) {
                std::cin >> attackStr;
                try {
                    attack = std::stoi(attackStr);
                    correctValue = true;
                }
                catch (std::invalid_argument ex) {
                    correctValue = false;
                    std::cout << "Incorect value\n";
                }
            }
            std::cout << "Old attack: " << weapon.GetAttack() << " new attack: " << attack << "\n";
            weapon.SetAttack(attack);
        }
    }*/
}

std::ostream& operator<<(std::ostream& o, const Item& item)
{
	item.Print(o);
	return o;
}
