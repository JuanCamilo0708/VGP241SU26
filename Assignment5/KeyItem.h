#pragma once
#include <string>
class KeyItem
{
public:
	KeyItem() {}
	KeyItem(const std::string& name, int amount);
	void Additem(int amount);
	void Consume(int amount);
	int GetCount() const;
	void Print();
private:
	std::string mName;
	int mCount = 0;

};
