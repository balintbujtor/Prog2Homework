#pragma once
#include "Vehicle.h"
#include "Garage.h"

class User
{
	double budget;
	int fuel;
public:
	Garage mygarage;
	User();

	double getBudget() const;
	int getFuel() const;

	void setBudget(double);

	void refuel(); //tankolo fv jo dr�g�n hogy ne legyen kedve a usernek

	void racefuel();
	
	void printData() const;


};

