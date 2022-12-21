#pragma once
#include "GroundVehicle.h"

class Camel : public GroundVehicle {
public:
	Camel() : GroundVehicle(10, 30) {}
	virtual VehicleType get_type() const { return VehicleTypeCamel; }
	double get_recovery_time(unsigned distance) override;
};