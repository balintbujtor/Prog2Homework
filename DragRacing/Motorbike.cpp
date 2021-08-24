#include "stdafx.h"
#include "Motorbike.h"
#include <iostream>
using namespace std;

Motorbike::Motorbike(int pCoeff, double pAcc, double pMax) : Vehicle(pAcc, pMax) , weight(pCoeff)
{
	//negativra figyelni!
}

double Motorbike::getCoefficient() const
{
	return weight;
}

void Motorbike::upgradeCoefficient()
{
	weight += 10;
}

void Motorbike::print() const
{
	cout << "Parameters of your Motorbike: " << endl
		<< "\t Acceleration: " << acceleration << "s" << endl
		<< "\t Maximal Speed: " << maxSpeed+weight << "m/s" << endl
		<< "\t Weight coefficient: " << weight << endl << endl;
}

double Motorbike::time() const
{
	double time = sqrt(2 * QUARTER_MILE / acceleration);

	if (time*acceleration > (maxSpeed+weight))
	{
		double timeOne = (weight+maxSpeed) / acceleration;
		double lengthOne = 0.5*acceleration*timeOne*timeOne;
		double lengthTwo = QUARTER_MILE - lengthOne;
		double timeTwo = lengthTwo / (maxSpeed+weight);

		time = timeOne + timeTwo;
	}

	return time;
}

Motorbike & Motorbike::operator=(const Motorbike & theOther)
{
	if (this == &theOther)
		return *this;
	acceleration = theOther.acceleration;
	maxSpeed = theOther.maxSpeed;
	weight = theOther.weight;

	return *this;
	// TODO: insert return statement here
}
