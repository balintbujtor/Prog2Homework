#pragma once
#include "Vehicle.h"
class Boat :
	public Vehicle
{
	double blade; // <= 1, az coefficient
public:
	Boat(int = 1, double = 10, double = 30);

	double getCoefficient() const;

	void upgradeCoefficient();

	void print() const;
	double time() const;

	Boat& operator=(const Boat&);
};