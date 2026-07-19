#pragma once
#include <string>
#include <Array.h>
enum Stats {
	Health,
	Attack,
	Defense,
	Stamina,
	Speed
};

class Player
{
public:
	Player() :stats{} {}
	Player(std::string name) : mName(name) {
		Initialize();
	};
	int GetStatByEnum(Stats stat) {
		return stats[stat];
	}
	int GetScore() { return mScore; }
	void SetScore(int score) {
		mScore = score;
	}
	void Display() {
		std::cout << mName << "\n"
			"Health:" << stats[0] << "\n"
			"Attack:" << stats[1] << "\n"
			"Defense:" << stats[2] << "\n"
			"Stamina:" << stats[3] << "\n"
			"Speed:" << stats[4] << "\n";
		std::cout << "/--------------------------/\n";
	}
private:
	void Initialize() {

		stats[0] = 100;
		for (int i = 1; i < 5; i++)
		{
			stats[i] = 1 + rand() % 5;
		}


	}
	std::string mName;
	Array<int, 5> stats;
	int mScore;
};