#include "Triangle.h"

Triangle::Triangle(unsigned* side_length) : Triangle()
{
    double a, b, c;
    a = _side_length[0];
    b = _side_length[1];
    c = _side_length[2];
    _corner_degree[0] = acos((a * a + c * c - b * b) / 2 * a * c);
    _corner_degree[1] = acos((a * a - c * c + b * b) / 2 * a * c);
    _corner_degree[2] = acos((c * c + b * b - a * a) / 2 * a * c);
}

bool 
Triangle::correct() {
    double corner_sum = std::accumulate(_corner_degree, _corner_degree + get_sides(), 0);
    if (corner_sum != 180) return false;
    return true;
}