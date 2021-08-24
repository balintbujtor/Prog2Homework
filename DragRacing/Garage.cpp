#include "stdafx.h"
#include "Garage.h"
#include <iostream>



Garage::Garage() : vehicleCount(0)
{
}

void Garage::printVehicles() const
{
	for (int i = 0; i < vehicleCount; i++)
	{
		garage[i]->print();
	}
}

int Garage::getVehicleCount() const
{
	return vehicleCount;
}

Vehicle * Garage::operator[](int index) const
{
	// figyel�nk a helyes indexel�sre
	if (!vehicleCount || index >= vehicleCount || index < 0)
		return nullptr;
	// visszaadjuk az indexelt Shape-re mutat� pointert
	return garage[index];
}


Garage::~Garage()
{
	for(int i = 0; i < vehicleCount; i++)
		delete garage[i];
}
