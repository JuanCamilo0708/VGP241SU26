#pragma once
#include <string>
enum ItemType {
    Sword,
    ChestPlate,
    Helmet,
    Boots,
    Pants,
    Potion,
    Bow,
    Arrow,
    Scythe,
    Axe,
    ITEM_COUNT
};
const std::string ItemNames[] =
{
    "Sword",
    "ChestPlate",
    "Helmet",
    "Boots",
    "Pants",
    "Potion",
    "Bow",
    "Arrow",
    "Scythe",
    "Axe"
};
class Item {
public:
    Item() = default;
    Item(ItemType itemType, int value);
    void ConsumeItem();
    void AddItem();
    ItemType GetType();
    std::string GetName();
    int GetCount();
    bool operator<(const Item& other) const {
        return mCount < other.mCount;
    }
private:
    ItemType mType;
    std::string mName;
    int mValue;
    int mCount = 0;
};
