#include "ShopApp.h"



ShopApp::ShopApp()
{
    menuText = R"(1. Show Weapons
2. Show Armors
3. Add Item
4. Delete Item
5. Modify Item
q. Quit
)";

    programRunning = true;

    weapons.emplace_back("Gungnir", 0.5, 1000, 50);
    weapons.emplace_back("Muramasa", 9.6, 500, 20);

    armors.emplace_back("Aegis", 88.4, 250, 999);
    armors.emplace_back("Havel", 12.2, 850, 2999);
}

void ShopApp::ClearConsole() {
#ifdef _WIN32
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
#endif

#ifdef linux
    std::system("clear");
#endif
    
}

void ShopApp::PressToCont()
{
    std::cout << "Pres Enter to continue\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void ShopApp::Run()
{
    while (programRunning) {
        
        ClearConsole();
        std::cout << menuText;
        std::cin >> pickedOption;
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (pickedOption == "1") {
            ShowWeapons();
        }
        else if (pickedOption == "2") {
            ShowArmors();
        }
        else if (pickedOption == "3") {
            AddItem();
        }
        else if (pickedOption == "4") {
            DeleteItem();
        }
        else if (pickedOption == "5") {
            ModifyItem();
        }
        else if (pickedOption == "q") {
            programRunning = false;
        }
        
    }
}



void ShopApp::ShowWeapons()
{
    ClearConsole();
    std::cout << "Weapons:\n";
    std::cout << "----------------\n";
    for (const Weapon& weapon : weapons) {
        std::cout << weapon;
        std::cout << "----------------\n";
    }
    PressToCont();
}

void ShopApp::ShowArmors()
{
    ClearConsole();
    std::cout << "Armors:\n";
    std::cout << "----------------\n";
    for (const Armor& armor : armors) {
        std::cout << armor;
        std::cout << "----------------\n";
    }
    PressToCont();
}

void ShopApp::AddItem()
{
    ClearConsole();
    std::cout <<
        "1. Add Weapon\n"
        "2. Add Armor\n";

    pickedOption = "";
    while (  !(pickedOption == "1" || pickedOption == "2") ) {
        std::cin >> pickedOption;
        if (pickedOption == "1") {
            AddWeapon();
        }
        else if (pickedOption == "2") {
            AddArmor();
        }
        else {
            std::cout << "Wrong option\n";
        }
    }
    
}



void ShopApp::AddWeapon()
{
    std::cout << "Pass weapon parameters in given order\n";
    std::cout << "Name weight price attack\n";

    std::string name, weightStr, priceStr, attackStr;
    float weight; 
    int attack, price;
    bool correctValues = false;

    while (correctValues == false) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> name >> weightStr >> priceStr >> attackStr;
        try {
            weight = std::stof(weightStr);
            price = std::stoi(priceStr);
            attack = std::stoi(attackStr);
            correctValues = true;
        }
        catch (std::invalid_argument ex) {
            std::cout << "Incorrect values\n";
            correctValues = false;
        }
    }
    
    weapons.emplace_back(name, weight, price, attack);
    std::cout << "Weapon added\n";
}



void ShopApp::AddArmor()
{
    std::cout << "Pass armor parameters in given order\n";
    std::cout << "Name weight price defence\n";

    std::string name, weightStr, priceStr, defenceStr;
    float weight;
    int defence, price;
    bool correctValues = false;

    while (correctValues == false) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> name >> weightStr >> priceStr >> defenceStr;
        try {
            weight = std::stof(weightStr);
            price = std::stoi(priceStr);
            defence = std::stoi(defenceStr);
            correctValues = true;
        }
        catch (std::invalid_argument ex) {
            std::cout << "Incorrect values\n";
            correctValues = false;
        }
    }

    armors.emplace_back(name, weight, price, defence);
    std::cout << "Armor added\n";
}

void ShopApp::DeleteItem()
{
    ClearConsole();
    int counter = 1;
    std::cout << "Weapons: \n";
    for (const Weapon& weapon : weapons) {
        std::cout << counter << ": " << weapon.GetName() << "\n";
        counter += 1;
    }
    std::cout << "Armors: \n";
    for (const Armor& armor : armors) {
        std::cout << counter << ": " << armor.GetName() << "\n";
        counter += 1;
    }

    int itemToDelete = 0;
    std::string itemToDeleteStr;
    while (itemToDelete < 1 || itemToDelete >= counter) {
        std::cin >> itemToDeleteStr;
        try {
            itemToDelete = std::stoi(itemToDeleteStr);
        }
        catch (std::invalid_argument ex) {
            continue;
        }
        if (itemToDelete < 1 || itemToDelete >= counter) {
            continue;
        }

        if (itemToDelete <= weapons.size()) {
            int weaponIndex = itemToDelete - 1;
            std::cout << "Weapon " << weapons[weaponIndex].GetName() << " was deleted\n";
            weapons.erase(weapons.begin() + weaponIndex);
        }
        else {
            int armorIndex = itemToDelete - armors.size() - 1;
            std::cout << "Armor " << armors[armorIndex].GetName() << " was deleted\n";
            armors.erase(armors.begin() + armorIndex);
        }

        PressToCont();
    }
    


}

void ShopApp::ModifyItem()
{
    ClearConsole();
    int counter = 1;
    std::cout << "Weapons: \n";
    for (const Weapon& weapon : weapons) {
        std::cout << counter << ": " << weapon.GetName() << "\n";
        counter += 1;
    }
    std::cout << "Armors: \n";
    for (const Armor& armor : armors) {
        std::cout << counter << ": " << armor.GetName() << "\n";
        counter += 1;
    }

    int itemToModify = 0;
    std::string itemToModifyStr;
    while (itemToModify < 1 || itemToModify >= counter) {
        std::cin >> itemToModifyStr;
        try {
            itemToModify = std::stoi(itemToModifyStr);
        }
        catch (std::invalid_argument ex) {
            continue;
        }

        if (itemToModify < 1 || itemToModify >= counter) {
            continue;
        }

        if (itemToModify <= weapons.size()) {
            int weaponIndex = itemToModify - 1;
            ModifyWeapon(weapons[weaponIndex]);
        }
        else {
            int armorIndex = itemToModify - armors.size() - 1;
            ModifyArmor(armors[armorIndex]);
        }

        PressToCont();
    }
}

void ShopApp::ModifyWeapon(Weapon& weapon)
{
    std::cout << "Curent statistics:\n";
    std::cout << weapon;
    std::cout << "1. Modify name\n";
    std::cout << "2. Modify weight\n";
    std::cout << "3. Modify price\n";
    std::cout << "4. Modify attack\n";

    pickedOption = "";

    while ( !(pickedOption == "1" || pickedOption == "2" || pickedOption == "3" || pickedOption == "4") ) {
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
    }
    
}



void ShopApp::ModifyArmor(Armor& armor)
{
    std::cout << "Curent statistics:\n";
    std::cout << armor;
    std::cout << "1. Modify name\n";
    std::cout << "2. Modify weight\n";
    std::cout << "3. Modify price\n";
    std::cout << "4. Modify defence\n";

    pickedOption = "";

    while ( !(pickedOption == "1" || pickedOption == "2" || pickedOption == "3" || pickedOption == "4") ) {
        std::cin >> pickedOption;
        bool correctValue = false;
        if (pickedOption == "1") {
            std::cout << "Enter new name: ";
            std::string name;
            std::cin >> name;
            std::cout << "New name of " << armor.GetName() << " is " << name << "\n";
            armor.SetName(name);
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
            std::cout << "Old weight: " << armor.GetWeight() << " new weight: " << weight << "\n";
            armor.SetWeight(weight);
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
            std::cout << "Old price: " << armor.GetPrice() << " new price: " << price << "\n";
            armor.SetPrice(price);
        }
        else if (pickedOption == "4") {
            std::cout << "Enter new defence value: ";
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
            std::cout << "Old defence: " << armor.GetDefence() << " new defence: " << attack << "\n";
            armor.SetDefence(attack);   
        }
        else {
            std::cout << "Wrong option\n";
        }
    }
}


