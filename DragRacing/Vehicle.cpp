#include "stdafx.h"
#include "Vehicle.h"
#include <iostream>
#include <math.h>

using namespace std;

Vehicle::Vehicle(double pAcc, double pMaxSpeed) : acceleration(pAcc), maxSpeed(pMaxSpeed)
{
	//figyelni a negativ értékekre
}

void Vehicle::upgradeAcceleration()
{
	acceleration *= 0.9;
}

void Vehicle::upgradeMaxSpeed()
{
	maxSpeed += 10;
}

double Vehicle::getAcceleration() const
{
	return acceleration;
}

double Vehicle::getMaxSpeed() const
{
	return maxSpeed;
}