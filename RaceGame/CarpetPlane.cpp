#include "CarpetPlane.h"

double 
CarpetPlane::get_reduced_distance(unsigned distance)
{
	if (distance < 1000) return distance;
	if (distance < 5000) return distance * (1 - 0.03);
	if (distance < 10000) return distance * (1 - 0.1);
	return distance * (1 - 0.05);
}