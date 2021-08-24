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
	// figyelünk a helyes indexelésre
	if (!vehicleCount || index >= vehicleCount || index < 0)
		return nullptr;
	// visszaadjuk az indexelt Shape-re mutató pointert
	return garage[index];
}


Garage::~Garage()
{
	for(int i = 0; i < vehicleCount; i++)
		delete garage[i];
}
