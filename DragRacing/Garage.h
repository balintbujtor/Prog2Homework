#pragma once
#include "Vehicle.h"
#include "Boat.h"
#include "Car.h"
#include "Motorbike.h"
class Garage
{
	int vehicleCount; // max h�rom
	Vehicle* garage[3]; //a h�romf�le j�rm�t�pust t�rolo tomb
public:
	Garage();

	template <class T>
	bool buy(T pvehicle) // ha nem vehet ujat akkor false
	{
		for (int i = 0; i < vehicleCount; i++)
		{
			T ptr = dynamic_cast<T>(garage[i]); // csak akkor engedi castolni ha az i-dik elem car, k�lonben null
			if (ptr) // akkor l�p be ha van m�r autoja, ekkor nem vehet ujat
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

