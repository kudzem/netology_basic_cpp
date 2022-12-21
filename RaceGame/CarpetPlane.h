#pragma once
#include "FlyingVehicle.h"

class CarpetPlane : public FlyingVehicle {
public:
	CarpetPlane() : FlyingVehicle(10) {}
	virtual VehicleType get_type() const { return VehicleTypeCarpetPlane; }
private:
	double get_reduced_distance(unsigned distance);
};