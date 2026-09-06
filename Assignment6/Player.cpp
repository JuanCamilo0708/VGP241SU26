#include "Player.h"
#include <format>
#include <iostream>
void Player::Initialize(const std::string& name)
{
	mName = name;
	mStats[0] = 100;
	mStats[1] = (rand() % 15) + 5;
	mStats[2] = (rand() % 80) + 20;
	mStats[3] = 1;

}

int Player::GetStat(Stats stat) const
{
	return mStats[stat];
}

void Player::SetStat(Stats stat, int value)
{
	mStats[stat] = value;
}
std::string Player::GetName() const 
{
	return mName;
}
bool Player::IsAlive() const
{
	return mStats[Stats::Health] > 0;
}

bool Player::operator<(const Player& rhs) const
{
	if (mStats[Stats::Health] == 0 || mStats[Stats::AttackCount] == 0) 
	{
		return 0 < rhs.mStats[Stats::Speed] ;
	}
	if (rhs.mStats[Stats::Health] == 0 || rhs.mStats[Stats::AttackCount] == 0)
	{
		return mStats[Stats::Speed] < 0;
	}
	return mStats[Stats::Speed] < rhs.mStats[Stats::Speed];
}

bool Player::operator>(const Player& rhs) const
{
	if (mStats[Stats::Health] <= 0 || mStats[Stats::AttackCount] <= 0)
	{
		return 0 > rhs.mStats[Stats::Speed];
	}
	if (rhs.mStats[Stats::Health] <= 0 || rhs.mStats[Stats::AttackCount] <= 0)
	{
		return mStats[Stats::Speed] > 0;
	}
	return mStats[Stats::Speed] > rhs.mStats[Stats::Speed];
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
	return os << std::format("Name: {:8s} Stats -> Health: {:3.0f} Attack: {:2.0f} Speed: {:3.0f}", player.mName,
		(float)player.mStats[0], (float)player.mStats[1], (float)player.mStats[2]);
}