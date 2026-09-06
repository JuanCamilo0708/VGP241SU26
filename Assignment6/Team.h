#pragma once
#include <Vector.h>
#include "Player.h"

class Team
{
public:
	Team() {}
	void Initialize(int numPlayers);
	Player* GetNextBattlingPlayer();
	void DamagePlayer(Player* player);
	int GetRemainingPlayers();
	void OrderPlayers();
	void StartTurn();
	void PrintTeam() const;
	
private:
	static int teamCount;
	std::string mName;
	Vector<Player> mPlayers;
};