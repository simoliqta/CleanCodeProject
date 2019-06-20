#include<iostream>
#include "Club.h"
#include "Player.h"
#include "FootballAssociation.h"
#include "FirstTeam.h"
#include "Reserve.h"
#include "Youth.h"
#include<vector>

using namespace std;

int main() {

	FootballAssociation BFU("Bulgarian Football Union", "Bulgaria");

	cout << "Welcome to Bank: " << BFU.getName() << " with address: " << BFU.getCountry() << endl;
	cout << "Following list of operations:" << endl;
	cout << "1 Display all club" << endl
		<< "2 Add new club" << endl
		<< "3 Delete existing clubs" << endl
		<< "4 Display all players" << endl
		<< "5 Display all players from e certain club" << endl
		<< "6 Add new Player" << endl
		<< "7 Delete Player" << endl
		<< "8 Display info for the Football Association" << endl
		<< "9 Quit" << endl;

	int operation = 0;

	while (operation != 9) {

		cin >> operation;

		switch (operation) {

			case 1:

				BFU.listClubs();
				break;

			case 2: {

				int ranking;
				cout << "Please input club ranking: ";
				cin >> ranking;
				cin.ignore();

				string ClubName;
				cout << "Please input club name: ";
				getline(cin, ClubName);

				string ClubCity;
				cout << "Please input club city: ";
				getline(cin, ClubCity);

				string ClubStadium;
				cout << "Please input club stadium name: ";
				getline(cin, ClubStadium);

				BFU.addClub(ranking, ClubName, ClubCity, ClubStadium);

				break;
			}

			case 3:

				unsigned long DeleteClubRanking;
				cout << "Please input the ranking of the club you want to delete: ";
				cin >> DeleteClubRanking;
				BFU.deleteClub(DeleteClubRanking);
				break;

			case 4:

				BFU.listPlayers();
				break;

			case 5:

				unsigned long ClubPlayersRanking;
				cout << "Please input ranking of the club which players you want to display: ";
				cin >> ClubPlayersRanking;
				BFU.listClubPlayers(ClubPlayersRanking);
				break;

			case 6: {
			
				string PlayerTeam;
				cout << "Please input player's team to be added to (choose from the following: FirstTeam, Reserve or Youth - capital letters matter!!!):";
				cin >> PlayerTeam;
				cin.ignore();

				string playerName;
				cout << "Please input player name: ";
				getline(cin, playerName);

				int clubRanking;
				cout << "Please input club ranking to which player will be added: ";
				cin >> clubRanking;
				cin.ignore();

				string playerPosition;
				cout << "Please input player position: ";
				getline(cin, playerPosition);

				double playerSalary;
				cout << "Please input player salary: ";
				cin >> playerSalary;

				BFU.addNewPlayer(PlayerTeam, playerName, clubRanking, playerPosition, playerSalary);

				break;
			}

			case 7: {
				string DeletePlayerName;
				cin.ignore();
				cout << "Please input the name of the player you want to delete: ";
				getline(cin, DeletePlayerName);
				BFU.removePlayer(DeletePlayerName);
				break;
			}

			case 8:

				BFU.display();
				break;

			case 9:

				break;
			}
	}

	return 0;
}