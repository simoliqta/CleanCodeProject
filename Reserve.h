#pragma once
#include<istream>
#include "Player.h"
using namespace std;

class Reserve : public Player {

	private:

		double gamesLeftToPlay;

	public:

		Reserve(const double newGamesLeftToPlay, const string newName, const string newPosition, const int newClubRanking, const double newSalary) : Player(newName, newPosition, newClubRanking, newSalary) {
			gamesLeftToPlay = newGamesLeftToPlay;
		}

		double getGamesLeftToPlay()const;

		void IncreaseSalary(const double addAmount);
		bool DecreaseSalary(const double removeAmount);
		void display();
};