#pragma once
#include "GroundVehicle.h"

class Centaur : public GroundVehicle {
public:
	Centaur() : GroundVehicle(15, 8) {}
	double get_recovery_time(unsigned distance) override;
	virtual VehicleType get_type() const { return VehicleTypeCentaur; }
};