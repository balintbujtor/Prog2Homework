#pragma once

class Vehicle
{
protected:
	static const double QUARTER_MILE; //static const --> helyfoglalás kell neki a mainben

	double acceleration; //sec-ben 0-rol 100-ra
	double maxSpeed; // m/s ban!!!!!!!!!!!!!!!

public:
	Vehicle(double=10, double=30);

	void upgradeAcceleration();
	void upgradeMaxSpeed();

	double getAcceleration() const;
	double getMaxSpeed() const;

	virtual void print() const = 0; //diagnosztikai kiirato fv
	virtual double time() const = 0; // a negyedmérföldes idõeredményt számító fv
	virtual void upgradeCoefficient() = 0;
	virtual double getCoefficient() const = 0;
};

