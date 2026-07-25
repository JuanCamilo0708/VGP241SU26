#include "Item.h"
#include <iostream>
Item::Item(ItemType itemType, int value):mType(itemType), mValue(value)
{
	mName = ItemNames[mType];
}

void Item::ConsumeItem()
{
	if (mCount > 0) {
		mCount--;
		std::cout << "Name: " << mName << " Value: " << mValue<<"\n";
	}
	else {
		std::cout << "Item does not have any to consume";
	}
}

void Item::AddItem()
{
	mCount++;
	std::cout << "Adding -> Name: " << mName << " New Count: " << mCount<<"\n\n";
}

ItemType Item::GetType()
{
	return mType;
}

std::string Item::GetName()
{
	return mName;
}

int Item::GetCount()
{
	return mCount;
}
