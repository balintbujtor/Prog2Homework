#pragma once
#include "Vehicle.h"
class Car : public Vehicle
{
	double nitro; // <= 1 coefficient - a gyorsulást csökkenti
public:
	Car(double = 1, double = 10, double = 30);

	void upgradeCoefficient();

	double getCoefficient() const;

	void print() const;
	double time() const;

	Car& operator=(const Car&);
};

