#include "Eagle.h"

double Eagle::distance_reduction_factor = 0.06;
double 
Eagle::get_reduced_distance(unsigned distance)
{
	return distance * (1 - distance_reduction_factor);
}