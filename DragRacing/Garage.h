#pragma once
#include "Vehicle.h"
#include "Boat.h"
#include "Car.h"
#include "Motorbike.h"
class Garage
{
	int vehicleCount; // max három
	Vehicle* garage[3]; //a háromféle jármûtípust tárolo tomb
public:
	Garage();

	template <class T>
	bool buy(T pvehicle) // ha nem vehet ujat akkor false
	{
		for (int i = 0; i < vehicleCount; i++)
		{
			T ptr = dynamic_cast<T>(garage[i]); // csak akkor engedi castolni ha az i-dik elem car, külonben null
			if (ptr) // akkor lép be ha van már autoja, ekkor nem vehet ujat
			{
				return false;
			}
		}

		garage[vehicleCount++] = pvehicle;

		return true;
	}

	void printVehicles() const;
	int getVehicleCount() const;
	Vehicle* operator[](int) const;
	~Garage();
};

