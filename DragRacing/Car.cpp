#include "stdafx.h"
#include "Car.h"
#include <iostream>
using namespace std;

Car::Car(double pCoeff, double pAcc, double pMax) : nitro(pCoeff) , Vehicle(pAcc, pMax)
{
	//figyelni a negatív értékekre!
}

void Car::upgradeCoefficient()
{
	nitro *= 0.9;
}

double Car::getCoefficient() const
{
	return nitro;
}

void Car::print() const
{
	cout << "Parameters of your Car: " << endl
		<< "\t Acceleration: " << acceleration*nitro << "s" << endl
		<< "\t Maximal Speed: " << maxSpeed << "m/s" << endl
		<< "\t Nitro coefficient: " << nitro << endl << endl;
}
double Car::time() const
{

	double time = sqrt(2 * QUARTER_MILE / (acceleration*nitro));

	if (time*acceleration*nitro > maxSpeed)
	{
		double timeOne = maxSpeed / (acceleration*nitro);
		double lengthOne = 0.5*acceleration*timeOne*timeOne*nitro;
		double lengthTwo = QUARTER_MILE - lengthOne;
		double timeTwo = lengthTwo / maxSpeed;

		time = timeOne + timeTwo;
	}

	return time;
}

Car & Car::operator=(const Car & theOther)
{
	if (this == &theOther)
		return *this;
	maxSpeed = theOther.maxSpeed;
	acceleration = theOther.acceleration;
	nitro = theOther.nitro;

	return *this;
	// TODO: insert return statement here
}

