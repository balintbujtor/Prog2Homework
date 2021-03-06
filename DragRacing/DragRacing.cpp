// DragRacing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vehicle.h"
#include "Boat.h"
#include "Car.h"
#include "Motorbike.h"
#include "User.h"
#include "Garage.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

const double Vehicle::QUARTER_MILE = 402.3; //helyfoglalás és értékadás a static constnak

void race(User& user)
{
	try {
		user.racefuel();  // uzemanyag csökkentése
	}
	catch (const std::out_of_range& e)
	{
		cout << "Your fuel level is: " << user.getFuel() << " ";
		cout << e.what();
		return;
	}
	double enemytime, yourtime;
	int option = 0;

	if (user.mygarage.getVehicleCount() > 1) // ha több autoja van
	{
		cout << "Choose your vehicle: ";
		user.printData();

		for (int i = 0; i < user.mygarage.getVehicleCount(); i++)
		{
			cout << "Enter " << i << " - Your " << i + 1 << ". vehicle \n";  // Enter 1 - Your 2. vehicle
		}

		try {
			cin >> option; //hanyadik autoval akar versenyezni
			if (option < 0 || option >(user.mygarage.getVehicleCount() - 1))
			{
				throw std::out_of_range("You do not have: ");
			}
		}
		catch (const std::out_of_range& e)
		{
			cout << e.what() << option + 1 << " vehicles." << endl;
			return;
		}

	}
	
	yourtime = user.mygarage[option]->time();  //kiválasztott auto ideje (ha egy van akkkor 0)

	srand(time(NULL)); // az rand-ot állitja - minden futtatáskor más lesz, ha különböző a fv argumentum - a tim(nullptr) az aktuális idot adja vissza kb :D lényeg h mindig mást

	enemytime = rand() % 300; // 0-299
	enemytime = ((enemytime / 100) - 1); // -1 - 1.99

	if (enemytime < 0) // ha kisebb mint nulla akkor jobb az ideje a usernél
	{
		cout << "You lost... Your time: " << yourtime << " enemy's time: " << enemytime + yourtime << endl;
	}
	else
	{
		cout << "You won! Your time: " << yourtime << " enemy's time: " << enemytime + yourtime << " you earned 20!" << endl;
		user.setBudget(20); //mindig ennyi pénzt kap ha nyer
	}

	user.printData();

}


void start(User& puser)
{
	
	int option;
	bool fail;

	do
	{
		cout << "Welcome to Drag Racing! \n Before we start you need to get a ride! \n You can choose: 1 - Car, 2 - Motorbike, 3 - Boat \n" << endl;
		//KEZELT
		cin >> option;

		switch (option)
		{
		case(1):
			puser.mygarage.buy(new Car);
			puser.setBudget(-100); //itt nem lehet gond - a startnál mindig 120 a tőke
			fail = false;
			break;
		case(2):
			puser.mygarage.buy(new Motorbike);
			puser.setBudget(-100); //ugyanez
			fail = false;
			break;
		case(3):
			puser.mygarage.buy(new Boat);
			puser.setBudget(-100); // ugyanez
			fail = false;
			break;
		default:
			cout << "You entered a wrong number... \n";
			fail = true;
		}
	} while (fail);
	


	cout << "Congratulations! You bought your first vehicle! \n";

	puser.printData();

	cout << "Now, let's race! \n [...] \n";

	race(puser);
}

void shop(User& user)
{
	int option;
	bool correct = true;
	bool correctUpgradeOption = true;
	bool correctVehicleType = true;
	do
	{ //loop amig jo adat nem jon

		cout << "Welcome to the shop! What do you want to buy? \n New vehicle - press 1 \n New upgrade - press 2 \n Fuel - press 3 \n";

		//kezelt
		cin >> option;
		switch (option)
		{
		case 1: // new vehicle
			int vehicleType;

			try {
				user.setBudget(-100);
			}
			catch (const std::out_of_range& e)
			{
				cout << e.what();
				cout << "Your budget is: " << user.getBudget() << "; the price of a new vehicle is 100.." << endl;
				return;
			}


			do { //addig csinálja amig jo adat nem jon be :)

				cout << "What type of vehicle do you want to buy? \n 1 - Car, 2 - Boat, 3 - Motorbike \n";

				//kezelt
				cin >> vehicleType;

				switch (vehicleType)
				{
					//ha az if false, akkor már van olyan járműve, nem vehet még egy azonosat
				case 1: //Car

					try {

						if (user.mygarage.buy(new Car) == false)
						{
							throw std::logic_error("You already have a Car... \n");
						}

					}
					catch (const std::logic_error& e)
					{
						cout << e.what();
						return;
					}

					user.mygarage.buy(new Car);
					cout << "The purchase was successful! Your budget is: " << user.getBudget() << endl;
					correctVehicleType = true;

					break;
				case 2: //Boat

					try {

						if (user.mygarage.buy(new Boat) == false)
						{
							throw std::logic_error("You already have a Boat...\n");
						}

					}
					catch (const std::logic_error& e)
					{
						cout << e.what();
						return;
					}

					user.mygarage.buy(new Boat);
					cout << "The purchase was succesful! Your budget is: " << user.getBudget() << endl;
					correctVehicleType = true;

					break;
				case 3: //Bike

					try {

						if (user.mygarage.buy(new Motorbike) == false)
						{
							throw std::logic_error("You already have a Motorbike...\n");
						}

					}
					catch (const std::logic_error& e)
					{
						cout << e.what();
						return;
					}

					user.mygarage.buy(new Motorbike);
					cout << "The purchase was succesful! Your budget is: " << user.getBudget() << endl;
					correctVehicleType = true;

					break;
				default:
				{
					cout << "You entered a wrong number...\n";
					correctVehicleType = false;
				}

				}
			} while (correctVehicleType == false);


			correct = true;
			break;
		case 2: // upgrade

			int upgradeoption, caroption;
			user.printData();

			try {
				user.setBudget(-20);
			}
			catch (const std::out_of_range& e)
			{
				cout << e.what();
				cout << "Your budget is: " << user.getBudget() << "; the price of an upgrade is 20.." << endl;
				return;
			}

			cout << "Which vehicle do you want to upgrade?" << endl;
			for (int i = 0; i < user.mygarage.getVehicleCount(); i++)
			{
				cout << "Enter " << i << " - Your " << i + 1 << ". vehicle \n";  // Enter 1 - Your 2. vehicle
			}

			
			try {
				cin >> caroption;  //melyik autot akarja upgradelni
				if (caroption < 0 || caroption > (user.mygarage.getVehicleCount() - 1))
				{
					throw std::out_of_range("You do not have: ");
				}
			}
			catch (const std::out_of_range& e)
			{
				cout << e.what() << caroption + 1 << " vehicles." << endl;
				return;
			}


			do {
				cout << "And what do you want to upgrade? \n 1 - Acceleration, 2 - MaxSpeed, 3 - Coefficient" << endl;

				//kezelt
				cin >> upgradeoption;
				switch (upgradeoption)
				{
				case 1: //Acceleration
					user.mygarage[caroption]->upgradeAcceleration();
					cout << "The purchase was succesful! Your budget is: " << user.getBudget() << endl;
					correctUpgradeOption = true;
					break;
				case 2: //MaxSpeed
					user.mygarage[caroption]->upgradeMaxSpeed();
					cout << "The purchase was succesful! Your budget is: " << user.getBudget() << endl;
					correctUpgradeOption = true;
					break;
				case 3: //Coefficient
					user.mygarage[caroption]->upgradeCoefficient();
					cout << "The purchase was succesful! Your budget is: " << user.getBudget() << endl;
					correctUpgradeOption = true;
					break;
				default:
					cout << "You entered a wrong number... \n";
					correctUpgradeOption = false;
				}
			} while (correctUpgradeOption == false);

			correct = true;
			break;
		case 3: // refuel
			try
			{
				user.refuel();
			}
			catch (const std::out_of_range& e)
			{
				cout << "You can not refuel your vehicle. Your budget is: " << user.getBudget() << endl;
				cout << e.what();
				cout << "Refueling costs 50 \n";
				return;
			}

			cout << "Your refueled your vehicle. Your budget is: " << user.getBudget() << endl;

			break;
		default:
		{
			cout << "You entered a wrong number...\n";
			correct = false;
		}

		}

	} while (correct == false);
}
	

void menu(User& user)
{
	int choice;
	bool run = true;
	do
	{
		cout << "Menu: Press the button to execute action" << endl << "1 - race; " << "2 - data; " << "3 - shop; " << "0 - exit" << endl;
		//kezelt
		cin >> choice;
		switch (choice)
		{
		case(1):
			race(user);
			
			break;
		case(2):
			user.printData();
			break;
		case(3):
			shop(user);
			break;
		case(0):
			run = false;
			break;
		default:
			cout << "You entered a wrong number! \n";
		}
	} 
	while (run);
}




int main()
{
	User user;
	start(user);
	menu(user);
}
