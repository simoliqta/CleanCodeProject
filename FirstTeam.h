#pragma once
#include<istream>
#include "Player.h"
using namespace std;

class FirstTeam : public Player {

	public:

		FirstTeam(const string newName, const string newPosition, const int newClubRanking, const double newSalary) : Player(newName, newPosition, newClubRanking, newSalary) {}

		void IncreaseSalary(const double addAmount);
		bool DecreaseSalary(const double removeAmount);
		void display();
};