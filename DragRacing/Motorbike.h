#pragma once
#include "Vehicle.h"
class Motorbike :
	public Vehicle
{
	double weight; // >= 0 - a maxSpeed-et noveli
public:
	Motorbike(int = 0, double = 10, double = 30);

	double getCoefficient() const;

	void upgradeCoefficient();

	void print() const;
	double time() const;

	Motorbike& operator=(const Motorbike&);
};

