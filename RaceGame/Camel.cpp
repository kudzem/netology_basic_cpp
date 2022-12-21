#include "Camel.h"

double 
Camel::get_recovery_time(unsigned distance) {
	unsigned intervals = get_recovery_intervals(distance);
	double recovery_time = (intervals > 0 ? 5 : 0) + ((intervals > 1) ? (intervals - 1) * 8 : 0);
	return recovery_time;
}