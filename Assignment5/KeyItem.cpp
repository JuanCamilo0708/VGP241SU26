#include "KeyItem.h"
#include <iostream>
KeyItem::KeyItem(const std::string& name, int amount)
	: mName(name), mCount(amount)
{
}
void KeyItem::Additem(int amount)
{
	mCount += amount;
}

void KeyItem::Consume(int amount)
{
	mCount -= amount;
}

int KeyItem::GetCount() const
{
	return mCount;
}
void  KeyItem::Print() {
	std::cout << mName << ": " << mCount << "\n";
}
