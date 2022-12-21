#pragma once
#include "FlyingVehicle.h"

class BroomStick : public FlyingVehicle {
public:
	BroomStick() : FlyingVehicle(20) {}
	virtual VehicleType get_type() const { return VehicleTypeBroomstick; }
private:
	double get_reduced_distance(unsigned distance);
};