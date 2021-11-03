#pragma once
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <vector>

#include "Item.h"

class ShopApp
{
private:

	std::string menuText;
	std::string pickedOption;
	bool programRunning;


	void ClearConsole();

public:
	ShopApp();
	void Run();
};

