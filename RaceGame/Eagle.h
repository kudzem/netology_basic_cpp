#pragma once
#include "FlyingVehicle.h"

class Eagle : public FlyingVehicle {
public:
	Eagle() : FlyingVehicle(8) {}
	virtual VehicleType get_type() const { return VehicleTypeEagle; }
private:
	double get_reduced_distance(unsigned distance);
	static double distance_reduction_factor;
};