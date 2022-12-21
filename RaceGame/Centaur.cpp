#include "Centaur.h"

double 
Centaur::get_recovery_time(unsigned distance) {
	unsigned intervals = get_recovery_intervals(distance);
	return intervals * 2;
}