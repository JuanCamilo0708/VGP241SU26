#include "Inventory.h"

void Inventory::Initialize() {
    mItems.PushBack(Item(Sword, 25));
    mItems.PushBack(Item(ChestPlate, 50));
    mItems.PushBack(Item(Helmet, 30));
    mItems.PushBack(Item(Boots, 15));
    mItems.PushBack(Item(Pants, 20));
    mItems.PushBack(Item(Potion, 40));
    mItems.PushBack(Item(Bow, 35));
    mItems.PushBack(Item(Arrow, 5));
    mItems.PushBack(Item(Scythe, 60));
    mItems.PushBack(Item(Axe, 45));
}

void Inventory::AddItem(ItemType itemType)
{
    for (int i = 0; i < mItems.Size(); i++)
    {
        if (mItems[i].GetType() == itemType) {
            mItems[i].AddItem();
        }
    }
}

void Inventory::DisplayInventory()
{
    PriorityQueue<Item> queue;
    for (int i = 0; i < mItems.Size(); ++i) {
        queue.Push(mItems[i]);
    }
    std::cout << "Diplaying Inventory\n";
    std::cout << "==========================================\n";
    for (int i = 0; i < queue.Size(); i++)
    {
        Item item = queue.Top();
        std::cout << item.GetName() << " x" << item.GetCount() << "\n";
        queue.Pop();
    }
    
}
