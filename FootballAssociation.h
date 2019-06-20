#pragma once
#include<istream>
#include<string>
#include<vector>
#include "Club.h"
#include "Player.h"
using namespace std;

class FootballAssociation {

	private:

		string name;
		string country;
		vector<Club> clubs;
		vector<Player*> players;

	public:

		FootballAssociation(FootballAssociation const& newFootballAssociation);
		~FootballAssociation();

		FootballAssociation(const string newName, const string newCountry);
		FootballAssociation(const string newName, const string newCountry, const vector<Club> newClubs, const vector<Player*> newPlayers);

		string getName()const;
		string getCountry()const;

		void addClub(const int clubRanking, const string clubName, const string clubCity, const string clubStadium);
		void listClubs();
		void deleteClub(const int clubRanking);

		void addNewPlayer(const string playerTeam, const string playerName, const int clubRanking, const string playerPosition, const double playerSalary);
		void removePlayer(const string playerName);
		void listPlayers();

		void listClubPlayers(const int clubRanking);

		void display();
};