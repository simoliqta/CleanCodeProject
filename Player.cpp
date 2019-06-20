#include<iostream>
#include "Player.h"
using namespace std;

Player::Player(const string newName, const string newPosition, const int newClubRanking, const double newSalary) {

	name = newName;
	position = newPosition;
	clubRanking = newClubRanking;
	salary = newSalary;
}

void Player::IncreaseSalary(const double addAmount) {

	salary = salary + addAmount;
}

bool Player::DecreaseSalary(const double removeAmount) {

	if (salary < removeAmount) return false;
	else {
		salary = salary - removeAmount;
		return true;
	}
}

void Player::display() {

	cout << "Player name is: " << name << endl;
	cout << "Player position is: " << position << endl;
	cout << "Player salary is: " << salary << endl;
}

double Player::getSalary()const {

	return salary;
}

void Player::setSalary(const double newAmount) {

	salary = newAmount;
}

string Player::getName()const {

	return name;
}
string Player::getPosition()const {

	return position;
}

int Player::getClubRanking()const {

	return clubRanking;
}