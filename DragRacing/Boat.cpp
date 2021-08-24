#include "stdafx.h"
#include "Boat.h"
#include <iostream>
using namespace std;


Boat::Boat(int pCoeff, double pAcc, double pMax) : Vehicle(pAcc, pMax), blade(pCoeff)
{
	//negativra figyelni!!
}

double Boat::getCoefficient() const
{
	return blade;
}

void Boat::upgradeCoefficient()
{
	blade *= 0.9;
}

void Boat::print() const
{
	cout << "Parameters of your Boat: " << endl
		<< "\t Acceleration: " << acceleration << "s" << endl
		<< "\t Maximal Speed: " << maxSpeed << "m/s" << endl
		<< "\t Blade coefficient: " << blade << endl << endl;
}

double Boat::time() const
{
	double time = sqrt(2 * QUARTER_MILE / acceleration);

	if (time*acceleration > maxSpeed)
	{
		double timeOne = maxSpeed / acceleration;
		double lengthOne = 0.5*acceleration*timeOne*timeOne;
		double lengthTwo = QUARTER_MILE - lengthOne;
		double timeTwo = lengthTwo / maxSpeed;

		time = timeOne + timeTwo;
	}

	time *= blade;
	return time;
}

Boat & Boat::operator=(const Boat &theOther)
{
	if (this == &theOther)
		return *this;
	acceleration = theOther.acceleration;
	maxSpeed = theOther.maxSpeed;
	blade = theOther.blade;

	return *this;
}
