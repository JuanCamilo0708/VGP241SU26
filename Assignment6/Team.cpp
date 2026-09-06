#include "Team.h"
#include <Global.h>
#include <iostream>
int Team::teamCount = 1;
void Team::Initialize(int numPlayers)
{
	mName = "Team " + std::to_string(teamCount);
	for (int i = 0; i < numPlayers; ++i)
	{
		Player player;
		player.Initialize("Player" + std::to_string(i + 1));
		mPlayers.PushBack(player);
	}
	teamCount++;
}

Player* Team::GetNextBattlingPlayer()
{
	return &mPlayers[0];
}

void Team::DamagePlayer(Player* player)
{
	player->SetStat(Stats::AttackCount, player->GetStat(Stats::AttackCount) - 1);
	Vector<Player*> alivePlayers;
	for (Player& player : mPlayers)
	{
		if (player.IsAlive())
		{
			alivePlayers.PushBack(&player);
		}
	}
	if (alivePlayers.Size() == 0)
	{
		return;
	}



	int randomIndex = rand() % alivePlayers.Size();
	Player* attacked = alivePlayers[randomIndex];

	int damageDealt = attacked->GetStat(Stats::Health) - player->GetStat(Stats::Attack);
	attacked->SetStat(Stats::Health, damageDealt);
	std::cout << player->GetName() << " attacked " << attacked->GetName()
		<< " of " << mName
		<< " for " << player->GetStat(Stats::Attack) 
		<< " of damage\n";

	//Speed Change
	int randNumber = (rand() % 100) + 1;
	if (randNumber < 25)
	{
		int speedChange = attacked->GetStat(Stats::Speed) - 10;
		if (speedChange <= 5)
		{

			attacked->SetStat(Stats::Speed, 5);
		}
		else
		{

			std::cout << "*---------------------------------------*\n"
				<< "The speed of " << attacked->GetName() << " got reduced by 10\n"
				<< "*---------------------------------------*\n";
			attacked->SetStat(Stats::Speed, speedChange);
		}

	}
	else if (randNumber > 90) {

		int speedChange = attacked->GetStat(Stats::Speed) + 5;
		std::cout << "*---------------------------------------*\n"
			<< "The speed of " << attacked->GetName() << " got increased by 5\n"
			<< "*---------------------------------------*\n";
		attacked->SetStat(Stats::Speed, speedChange);
	}

}

int Team::GetRemainingPlayers()
{
	int count = 0;
	for (int i = 0; i < mPlayers.Size(); i++)
	{
		if (mPlayers[i].GetStat(Stats::Health) > 0)
		{
			count++;
		}
	}
	return count;
}

void Team::OrderPlayers()
{
	Global::IntroSort(mPlayers.begin(), mPlayers.end(), std::greater<Player>());
}

void Team::StartTurn()
{
	for (int i = 0; i < mPlayers.Size(); i++)
	{
		if (mPlayers[i].IsAlive())
		{
			mPlayers[i].SetStat(Stats::AttackCount, 1);
		}
	}
	OrderPlayers();

}
void Team::PrintTeam() const
{
	std::cout << "Team " << mName << "\nPlayers:\n";
	for (int i = 0; i < mPlayers.Size(); i++)
	{
		if (mPlayers[i].IsAlive())
		{
			std::cout << mPlayers[i] << "\n";
		}

	}
}