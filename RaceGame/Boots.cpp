#include "Boots.h"

double 
Boots::get_recovery_time(unsigned distance) {
	unsigned intervals = get_recovery_intervals(distance);
	double recovery_time = (intervals > 0 ? 10 : 0) + ((intervals > 1) ? (intervals - 1) * 5 : 0);
	return recovery_time;
}