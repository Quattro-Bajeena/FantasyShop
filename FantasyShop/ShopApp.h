#pragma once
#ifdef _WIN32
#include <Windows.h>
#endif

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <vector>

#include "Item.h"
#include "Weapon.h"
#include "Armor.h"

class ShopApp
{
private:

	std::string menuText;
	std::string pickedOption;
	bool programRunning;

	std::vector<Weapon> weapons;
	std::vector<Armor> armors;

	void ClearConsole();
	void PressToCont();

	void ShowWeapons();
	void ShowArmors();

	void AddItem();
	void AddWeapon();
	void AddArmor();

	void DeleteItem();

	void ModifyItem();
	void ModifyWeapon(Weapon& weapon);
	void ModifyArmor(Armor& armor);

public:
	ShopApp();
	void Run();
};

