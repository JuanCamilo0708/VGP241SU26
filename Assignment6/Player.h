#pragma once
#include <string>
#include <Array.h>
enum Stats
{
	Health,
	Attack,
	Speed,
	AttackCount
};

class Player
{
public:
	void Initialize(const std::string& name);
	int  GetStat(Stats stat) const;
	void SetStat(Stats stat, int value);
	std::string GetName() const;
	bool IsAlive() const;
	bool operator<(const Player& rhs) const;
	bool operator>(const Player& rhs) const;

	friend std::ostream& operator<<(std::ostream& os, const Player& player);
	
private:
	std::string mName;
	Array<int,4> mStats;

};