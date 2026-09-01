// Assignment5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Inventory.h"
#include <Vector.h>
int main()
{
	Inventory* inventory = Inventory::Get();
	Vector <std::string> keyNames;
	for (int i = 0; i < 20; i++)
	{
		std::string name = "key" + std::to_string(i + 1);
		keyNames.PushBack(name);
	}
	for (int i = 0; i < 100; i++)
	{
		int index = rand() % 20;
		inventory->PickupKey(keyNames[index], 1+ (rand() % 5));
	}
	Vector < std::string> keys;
	inventory->mKeys.ObtainKeys(keys);
	for (int i = 0; i < keys.Size(); i++)
	{
		inventory->mKeys[keys[i]].Print();
	}
	int countDoorsOpen = 0;
	int countDoorsFailed = 0;
	bool gameLoop = true;
	while (gameLoop) {
		int input = 0;
		std::cout << "Select an option\n"
			"1. Open Door\n"
			"2. PickUp Key\n"
			"3. Exit\n";
		std::cin >> input;
		int index = rand() % 20;
		std::string key = keyNames[index];
		
		
		switch (input)
		{
		case 1:
			std::cout << "You arrive at a door and need a " << key <<"\n";
			if (inventory->mKeys.Has(key)) {
				inventory->UseKey(key, 1);
				std::cout << "You have the " << key << " and have unlocked the door\n";
				countDoorsOpen++;
			}
			else {
				std::cout << "You do not have the " << key << ", the door will remain locked\n";
				countDoorsFailed++;
			}
			break;
		case 2:
			
			inventory->PickupKey(keyNames[index], 1);
			std::cout << keyNames[index] << " have been added\n";
			break;
		case 3:
			gameLoop = false;
			std::cout << "Number of Doors opened: " << countDoorsOpen << "\n";
			std::cout << "Number of Doors failed to open: " << countDoorsFailed << "\n";
			keys.Clear();
			inventory->mKeys.ObtainKeys(keys);
			for (int i = 0; i < keys.Size(); i++)
			{
				inventory->mKeys[keys[i]].Print();
			}
			break;
		default:
			break;
		}
	}

}
