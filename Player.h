#pragma once
#include<istream>
#include<string>
using namespace std;

class Player {

	private:

		string name;
		string position;
		int clubRanking;
		double salary;

	public:

		Player(const string newName, const string newPosition, const int newClubRanking, const double newSalary);

		virtual void IncreaseSalary(const double addAmount);
		virtual bool DecreaseSalary(const double removeAmount);
		virtual void display();

		double getSalary()const;
		void setSalary(const double newAmount);

		string getName()const;
		string getPosition()const;

		int getClubRanking()const;
};