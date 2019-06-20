#include<iostream>
#include "FirstTeam.h"

using namespace std;

void FirstTeam::IncreaseSalary(const double addAmount) {

	Player::IncreaseSalary(addAmount);
}

bool FirstTeam::DecreaseSalary(const double removeAmount) {

	if (getSalary() < removeAmount) return false;
	else {
		double salary = getSalary() - removeAmount;
		setSalary(salary);
		return true;
	}
}

void FirstTeam::display() {

	cout << "Player plays in: First team" << endl;
	Player::display();
}