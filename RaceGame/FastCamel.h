#pragma once
#include "GroundVehicle.h"

class FastCamel : public GroundVehicle {
public:
	FastCamel() : GroundVehicle(40, 10) {}
	double get_recovery_time(unsigned distance) override;
	virtual VehicleType get_type() const { return VehicleTypeFastCamel; }
};
