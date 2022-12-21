#include "Broomstick.h"

double 
BroomStick::get_reduced_distance(unsigned distance)
{
	return distance * (1 - (distance / 1000) * 0.01);
}