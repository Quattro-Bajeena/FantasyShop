#include "ShopApp.h"

ShopApp::ShopApp()
{
    menuText = R"(1. Show Weapons
2. Show Armors
3. Show Accesories
4. Add Item
5. Delete Item
6. Modify Item
q. Quit
)";

    programRunning = true;
}

void ShopApp::ClearConsole() {
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

void ShopApp::Run()
{
    while (programRunning) {
        ClearConsole();
        std::cout << menuText;
        std::cin >> pickedOption;

        if (pickedOption == "1") {
            ClearConsole();

            std::cout <<
                "Weapon 1\n"
                "Weapon 2\n"
                "Weapon 3\n";

            std::cin >> pickedOption;
        }
        else if (pickedOption == "2") {
            ClearConsole();
            std::cout <<
                "Armor 1\n"
                "Armor 2\n"
                "Armor 3\n";
            std::cin >> pickedOption;
        }
        else if (pickedOption == "3") {
            ClearConsole();
            std::cout <<
                "Accesory 1\n"
                "Accesory 2\n"
                "Accesory 3\n";
            std::cin >> pickedOption;
        }
        else if (pickedOption == "4") {
            ClearConsole();
            std::cout <<
                "1. Add Weapon\n"
                "2. Add Armor\n"
                "3. Add Accesory\n";
            std::cin >> pickedOption;
        }
        else if (pickedOption == "5") {
            ClearConsole();
            std::cout <<
                "1. Delete Weapon\n"
                "2. Delete Armor\n"
                "3. Delete Accesory\n";
            std::cin >> pickedOption;
        }
        else if (pickedOption == "6") {
            ClearConsole();
            std::cout <<
                "1. Modyfiy Weapon\n"
                "2. Modyfiy Armor\n"
                "3. Modyfiy Accesory\n";
            std::cin >> pickedOption;
        }
        else if (pickedOption == "q") {
            programRunning = false;
        }
    }
}
