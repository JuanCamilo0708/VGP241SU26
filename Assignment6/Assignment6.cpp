#include "Team.h"
#include <iostream>
int main()
{
	srand(time(nullptr));
	Team team1;
	team1.Initialize(20);
	Team team2;
	team2.Initialize(20);
	while (team1.GetRemainingPlayers() > 0 && team2.GetRemainingPlayers() > 0)
	{
		team1.StartTurn();
		team2.StartTurn();
		team1.PrintTeam();
		team2.PrintTeam();
		std::cout << "----------------------------------------------------------------------\n";
		while (true)
		{
			
			Player* playerTeam1 = team1.GetNextBattlingPlayer();
			Player* playerTeam2 = team2.GetNextBattlingPlayer();
			if (playerTeam1->GetStat(AttackCount) == 0 && playerTeam2->GetStat(AttackCount) == 0)
			{
				break;
			}
			if (*playerTeam1 > *playerTeam2)
			{
				team2.DamagePlayer(playerTeam1);
			}
			else
			{
				team1.DamagePlayer(playerTeam2);
			}
			team1.OrderPlayers();
			team2.OrderPlayers();
			
		}
		std::cout << "----------------------------------------------------------------------\n";


	}

	std::cout << "----------------------------------------------------------------------" <<
		"\nThis was the winning team\n";
	if (team1.GetRemainingPlayers() != 0)
	{
		team1.StartTurn();
		team1.PrintTeam();
	}
	else 
	{
		team2.StartTurn();
		team2.PrintTeam();
	}
	std::cout << "----------------------------------------------------------------------\n";
}
