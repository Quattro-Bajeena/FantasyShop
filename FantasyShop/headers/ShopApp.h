#pragma once
#ifdef _WIN32
#define NOMINMAX
#include <Windows.h>
#endif

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <limits>

#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Manager.h"


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

	// OBRONA C++ ZADANIE
	Manager manager;
	void Sumowanie();


public:
	ShopApp();
	void Run();
};

