#pragma once
#include<Map.h>
#include "KeyItem.h"
class Inventory {
public:
	static Inventory* Get();
	void PickupKey(const std::string& keyName, int amount);
	void UseKey(const std::string& keyName, int amount);
	bool Has(const std::string& keyName);
	Map<std::string, KeyItem> mKeys;

};