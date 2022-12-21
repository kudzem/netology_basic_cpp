#pragma once
#include "Vehicle.h"

class GroundVehicle : public Vehicle {
public:
	GroundVehicle(unsigned speed, unsigned active_time) :
		Vehicle(speed), _active_time(active_time) {}

	__declspec(dllexport) double get_race_time(unsigned distance) override;
	virtual double get_recovery_time(unsigned distance) = 0;

protected:
	unsigned _active_time;
	unsigned get_recovery_intervals(unsigned distance);
};