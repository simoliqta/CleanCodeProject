#include<iostream>
#include "Club.h"

using namespace std;

Club::Club(const int newRanking, const string newName, const string newCity, const string newStadium) {

	ranking = newRanking;
	name = newName;
	city = newCity;
	stadium = newStadium;
}

int Club::getRanking()const {

	return ranking;
}

string Club::getName()const {

	return name;
}

string Club::getCity()const {

	return city;
}

string Club::getStadium()const {

	return stadium;
}

void Club::setRanking(const int newRanking) {

	ranking = newRanking;
}

void Club::setName(const string newName) {

	name = newName;
}

void Club::setCity(const string newCity) {

	city = newCity;
}

void Club::setStadium(const string newStadium) {

	stadium = newStadium;
}

void Club::display() {

	cout << "Club ranking: " << ranking << endl;
	cout << "Club name: " << name << endl;
	cout << "Club city: " << city << endl;
	cout << "Club stadium: " << stadium << endl;
}