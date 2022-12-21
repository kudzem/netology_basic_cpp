#pragma once
#include "GroundVehicle.h"

class Boots : public GroundVehicle {
public:
	Boots() : GroundVehicle(6, 60) {}
	double get_recovery_time(unsigned distance) override;
	virtual VehicleType get_type() const { return VehicleTypeBoots; }
};