#include <iostream>
#include "Player.h"
#include <Vector.h>
#include <Array.h>
std::string GetRandomName() {
	std::string names[20] = {
	"Arclen",
	"Virella",
	"Thornecrest",
	"Kaelis",
	"Brimholt",
	"Solvandar",
	"Nyxara",
	"Halden",
	"Marrowind",
	"Eryndor",
	"Vaelix",
	"Dravenfall",
	"Liora",
	"Fenwick",
	"Astryx",
	"Calderon",
	"Sylvane",
	"Torvath",
	"Mirelune",
	"Jaxen"
	};
	int index = rand() % 20;
	return names[index];

}
int Result(Player& player1, Player& player2) {
	int player1Score = player1.GetStatByEnum(Stats::Health)
		- ((player2.GetStatByEnum(Stats::Attack) * player2.GetStatByEnum(Stats::Stamina))
			- (player1.GetStatByEnum(Stats::Defense) * player1.GetStatByEnum(Stats::Speed)));
	int player2Score = player2.GetStatByEnum(Stats::Health)
		- ((player1.GetStatByEnum(Stats::Attack) * player1.GetStatByEnum(Stats::Stamina))
			- (player2.GetStatByEnum(Stats::Defense) * player2.GetStatByEnum(Stats::Speed)));
	player1.SetScore(player1Score);
	player2.SetScore(player2Score);
	return player1Score - player2Score;
}
void TieBreaker(Player& player1, Player& player2) {
	int number = rand() % 100;
	if (number < 50) {
		std::cout << "The Winner is";
		player1.Display();
		return;
	}
	player2.Display();

}
int main()
{
	srand(time(NULL));
	Vector<Player> players;
	for (int i = 0; i < 10; ++i)
	{
		players.PushBack(Player(GetRandomName()));
	}

	for (Player& player : players) {
		player.Display();

	}
	for (int i = 0; i < 6; i++)
	{
		players.PopBack();
	}
	for (int i = 0; players.Size() < 20; i++) {
		players.PushBack(Player(GetRandomName()));
	}
	Player player1 = players[rand() % 20];
	Player player2 = players[rand() % 20];
	std::cout << "Players Picked\n";
	std::cout << "/--------------------------/\n";
	int result = Result(player1, player2);
	std::cout << "Player 1:\n";
	player1.Display();
	std::cout << "Player 2:\n";
	player2.Display();

	std::cout << "Score: \n"
		"Player 1: " << player1.GetScore() << std::endl <<
		"Player 2: " << player2.GetScore() << std::endl;
	std::cout << "/--------------------------/\n";
	if (result < 0) {
		std::cout << "Winner\n";
		player2.Display();
	}
	else if (result > 0) {
		std::cout << "Winner\n";
		player1.Display();
	}
	else {
		std::cout << "There is a tie flipping a coin\n";
		TieBreaker(player1, player2);
	}

}

