#include "GroundVehicle.h"

double 
GroundVehicle::get_race_time(unsigned distance) {
	return (double)distance / _speed + get_recovery_time(distance);
}

unsigned 
GroundVehicle::get_recovery_intervals(unsigned distance) {
	double intervals = std::ceil((double)distance / _speed / _active_time) - 1;
	return intervals;
}