#include "FastCamel.h"

double
FastCamel::get_recovery_time(unsigned distance) {
	unsigned intervals = get_recovery_intervals(distance);

	double recovery_time = ((intervals > 0) ? 5 : 0) +
		                   ((intervals > 1) ? 6.5 : 0) +
		                   ((intervals > 2) ? (intervals - 2) * 8 : 0);
	return recovery_time;
}