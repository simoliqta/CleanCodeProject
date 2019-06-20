#include<iostream>
#include "FootballAssociation.h"
#include "FirstTeam.h"
#include "Reserve.h"
#include "Youth.h"

using namespace std;

FootballAssociation::FootballAssociation(FootballAssociation const& newFootballAssociation) {

	name = newFootballAssociation.getName();
	country = newFootballAssociation.getCountry();

	for (int i = 0; i < newFootballAssociation.clubs.size(); i++) {
		clubs[i] = newFootballAssociation.clubs[i];
	}
	for (int i = 0; i < players.size(); i++) {
		players[i] = newFootballAssociation.players[i];
	}
}

FootballAssociation::~FootballAssociation() {

	for (int i = 0; i < players.size(); i++) {
		delete[] players[i];
	}
}

FootballAssociation::FootballAssociation(const string newName, const string newCountry) {

	name = newName;
	country = newCountry;
}

FootballAssociation::FootballAssociation(const string newName, const string newCountry, const vector<Club> newClubs, const vector<Player*> newPlayers) {

	name = newName;
	country = newCountry;
	
	for (int i = 0; i < newClubs.size(); i++) {
		clubs.push_back(newClubs[i]);
	}
	
	for (int i = 0; i < newPlayers.size(); i++) {
		players.push_back(newPlayers[i]);
	}
}

string FootballAssociation::getName()const {

	return name;
}

string FootballAssociation::getCountry()const {

	return country;
}

void FootballAssociation::addClub(const int clubRanking, const string clubName, const string clubCity, const string clubStadium) {

	int counter;
	for (counter = 0; counter < clubs.size(); counter++) {
		if (clubs[counter].getRanking() == clubRanking) break;
	}
	if (counter == clubs.size()) {
		Club newClub(clubRanking, clubName, clubCity, clubStadium);
		clubs.push_back(newClub);
	}
	else {
		cout << "There is already club with ranking " << clubRanking << " in the association" << endl;
		return;
	}
}
void FootballAssociation::listClubs() {

	if (clubs.size() == 0) {
		cout << "There are no clubs registrated in the association! Please register some first!" << endl;
		return;
	}
	else {
		for (int i = 0; i < clubs.size(); i++) {
			cout << "------CLUB " << i + 1 << "------" << endl;
			clubs[i].display();
			cout << endl;
		}
	}
}
void FootballAssociation::deleteClub(const int clubRanking) {

	int i;
	for (i = 0; i < clubs.size(); i++) {
		if (clubs[i].getRanking() == clubRanking) {
			clubs.erase(clubs.begin() + i);

			//remove all players of the selected club
			for (int j = 0; j < players.size(); j++) {
				if (players[j]->getClubRanking() == clubRanking) {
					players.erase(players.begin() + j);
				}
			}
			return;
		}
	}
	if (i == clubs.size()) {
		cout << "There is not a club with ranking: " << clubRanking << " in the association" << endl;
	}
	return;
}

void FootballAssociation::addNewPlayer(const string playerTeam, const string playerName, const int clubRanking, const string playerPosition, const double playerSalary) {

	int counter;
	//check if the player is already in the association
	for (int i = 0; i < players.size(); i++) {
		if (players[i]->getName() == playerName) {
			cout << "This player is already in the association!" << endl;
			return;
		}
	}
	for (counter = 0; counter < clubs.size(); counter++) {
		if (clubs[counter].getRanking() == clubRanking) break;
	}
	if (counter == clubs.size()) {
		cout << "There is not a club with ranking: " << clubRanking << " in the association" << endl;
		return;
	}
	else {
		if (playerTeam == "Reserve") {
			double gamesLeftToPlay;
			cout << "Please input games left to play for the player to become member of firts team: ";
			cin >> gamesLeftToPlay;
			//Reserve(const double newGamesLeftToPlay, const string newName, const string newPosition, const double newSalary)
			Reserve* newReserve = new Reserve(gamesLeftToPlay, playerName, playerPosition, clubRanking, playerSalary);
			players.push_back(newReserve);
		}
		else if (playerTeam == "Youth") {
			double yearsLeft;
			cout << "Please input years left to play for the player to become member of reserves team: ";
			cin >> yearsLeft;
			Youth* newYouth = new Youth(yearsLeft, playerName, playerPosition, clubRanking, playerSalary);
			players.push_back(newYouth);
		}
		else {
			FirstTeam* _newFirstTeam = new FirstTeam(playerName, playerPosition, clubRanking, playerSalary);
			players.push_back(_newFirstTeam);
		}
	}
}

void FootballAssociation::removePlayer(const string playerName) {
	
	for (int i = 0; i < players.size(); i++) {
		if (players[i]->getName() == playerName) {
			players.erase(players.begin() + i);
			return;
		}
	}
	cout << "There is not such player in the association!!!" << endl;
	return;
}

void FootballAssociation::listPlayers() {
	
	if (players.size() == 0) {
		cout << "There are not any players in the association please add some first!" << endl;
		return;
	}
	for (int i = 0; i < players.size(); i++) {
		cout << "------PLAYER " << i + 1 << "------" << endl;
		players[i]->display();
		cout << endl;
	}
}

void FootballAssociation::listClubPlayers(const int clubRanking) {
	
	for (int i = 0; i < players.size(); i++) {
		if (players[i]->getClubRanking() == clubRanking) {
			players[i]->display();
		}
	}
}

void FootballAssociation::display() {

	cout << "Information about the Football Association(FA):" << endl;
	cout << "Name of FA is: " << name << endl;
	cout << "Country of FA is: " << country << endl;
	cout << "Number of clubs in FA is: " << clubs.size() << endl;
	cout << "Number of players in FA is: " << players.size() << endl;
}