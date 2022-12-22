#pragma once

#include <vector>
#include <iostream>

enum VehicleType {
	VehicleTypeBroomstick,
	VehicleTypeEagle,
	VehicleTypeCarpetPlane,
	VehicleTypeCentaur,
	VehicleTypeCamel,
	VehicleTypeFastCamel,
	VehicleTypeBoots,
	VehicleTypeLast // should be last and do not use it
};

__declspec(dllimport) extern const char* VehicleTypeStr[];

class Vehicle {
public:
	Vehicle(unsigned speed) : _speed(speed) {}
	virtual ~Vehicle() {}
	virtual double get_race_time(unsigned distance) = 0;
	virtual VehicleType get_type() const = 0;
protected:
	unsigned _speed;
};