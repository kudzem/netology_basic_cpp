#pragma once
#include "Vehicle.h"

class FlyingVehicle : public Vehicle {
public:
	FlyingVehicle(unsigned speed) : Vehicle(speed) {}
	double get_race_time(unsigned distance) override { return (get_reduced_distance(distance) / _speed); }
private:
	virtual double get_reduced_distance(unsigned distance) = 0;
};