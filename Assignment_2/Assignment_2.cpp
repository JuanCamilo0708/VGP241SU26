
#include <iostream>
#include <PriorityQueue.h>
#include "Inventory.h"
int main()
{
	Inventory inventory;

	inventory.Initialize();
	for (int i = 0; i < 100; i++)
	{
		ItemType itemType = (ItemType)(rand() % ITEM_COUNT);
		inventory.AddItem(itemType);
	}

	inventory.DisplayInventory();
}
