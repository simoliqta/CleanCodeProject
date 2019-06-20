#include<iostream>
#include "Youth.h"

using namespace std;

double Youth::getYearsLeft()const {

	return yearsLeft;
}

void Youth::IncreaseSalary(const double addAmount) {

	Player::IncreaseSalary(addAmount);
}

bool Youth::DecreaseSalary(const double removeAmount) {

	if (getSalary() < removeAmount) return false;
	else {
		double salary = getSalary() - removeAmount;
		setSalary(salary);
		return true;
	}
}

void Youth::display() {

	cout << "Player plays in: Youths team" << endl;
	Player::display();
	cout << "Years left to become member of reserves team: " << yearsLeft << endl;
}