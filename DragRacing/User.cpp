#include "stdafx.h"
#include "User.h"
#include <iostream>
using namespace std;

double User::getBudget() const
{
	return budget;
}

int User::getFuel() const
{
	return fuel;
}

void User::setBudget(double pBudget)
{
	if (budget + pBudget < 0)
	{
		throw std::out_of_range("Your do not have enough budget for this action. \n");
	}
		budget += pBudget;
}

void User::refuel()
{
	fuel += 5;
	setBudget(-50);

}

void User::racefuel()
{
	if (fuel == 0)
	{
		throw std::out_of_range("The fuel level can't go below 0. \n");
	}
	fuel -= 1;
}

void User::printData() const
{
	cout << "The data of the User: " << endl
		<< "\t Budget: " << budget << endl
		<< "\t Fuel: " << fuel << endl;
	mygarage.printVehicles();
}

User::User() : budget(120) , fuel(5)
{
}
