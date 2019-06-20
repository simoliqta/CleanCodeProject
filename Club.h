#pragma once
#include<istream>
#include<string>

using namespace std;

class Club {

	private:

		int ranking;
		string name;
		string city;
		string stadium;

	public:

		Club(const int newRanking, const string newName, const string newCity, const string newStadium);
		int getRanking()const;
		string getName()const;
		string getCity()const;
		string getStadium()const;

		void setRanking(const int newRanking);
		void setName(const string newName);
		void setCity(const string newCity);
		void setStadium(const string newStadium);

		void display();

};