#pragma once
#include<istream>
#include "Player.h"

using namespace std;

class Youth : public Player {

	private:

		double yearsLeft;

	public:

		Youth(const double newYearsLeft, const string newName, const string newPosition, const int newClubRanking, const double newSalary) : Player(newName, newPosition, newClubRanking, newSalary) {
			yearsLeft = newYearsLeft;
		}

		double getYearsLeft()const;

		void IncreaseSalary(const double addAmount);
		bool DecreaseSalary(const double removeAmount);
		void display();
};