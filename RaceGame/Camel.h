#pragma once
#include "GroundVehicle.h"

class Camel : public GroundVehicle {
public:
	Camel() : GroundVehicle(10, 30) {}
	virtual VehicleType get_type() const { return VehicleTypeCamel; }
	__declspec(dllexport) double get_recovery_time(unsigned distance) override;
};