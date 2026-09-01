#include "Inventory.h"

Inventory* Inventory::Get() {
	static Inventory sInstance;
	return &sInstance;
}
void Inventory::PickupKey(const std::string& keyName, int amount)
{
	if (mKeys.Has(keyName)) {
		mKeys[keyName].Additem(amount);
		return;
	}
	mKeys.Insert(keyName, KeyItem(keyName, amount));

}

void Inventory::UseKey(const std::string& keyName, int amount)
{
	if (mKeys.Has(keyName))
	{
		if (mKeys[keyName].GetCount() <= 0)
		{
			mKeys.Remove(keyName);
			return;
		}
		mKeys[keyName].Consume(amount);
		return;
	}
}

