#include<iostream>
#include "Reserve.h"

using namespace std;

double Reserve::getGamesLeftToPlay()const {

	return gamesLeftToPlay;
}

void Reserve::IncreaseSalary(const double addAmount) {

	Player::IncreaseSalary(addAmount);
}

bool Reserve::DecreaseSalary(const double removeAmount) {

	if (getSalary() < removeAmount) return false;
	else {
		double salary = getSalary() - removeAmount;
		setSalary(salary);
		return true;
	}

}

void Reserve::display() {

	cout << "Player plays in: Reserves team" << endl;
	Player::display();
	cout << "Player's games to play left to become member of firts team: " << gamesLeftToPlay << endl;
}