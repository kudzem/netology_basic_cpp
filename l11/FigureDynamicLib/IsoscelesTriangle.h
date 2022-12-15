#pragma once
#include "Triangle.h"
#include <math.h>
#define _USE_MATH_DEFINES

enum class IsoscelesTriangleSide {
    Thigh,
    Base
};
//FIGURELIB_API
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double A, double side, IsoscelesTriangleSide sideType) : Triangle()
    {
        _corner_degree[0] = A;
        _corner_degree[1] = (180 - A) / 2;
        _corner_degree[2] = _corner_degree[1];

        if (sideType == IsoscelesTriangleSide::Thigh) {
            _side_length[0] = _side_length[1] = side;
            _side_length[2] = sqrt(2 * side * side * (1 - cos(A / 180 * M_PI)));
        }
        else if (sideType == IsoscelesTriangleSide::Base) {
            _side_length[2] = side;
            _side_length[0] = _side_length[1] = sqrt(side * side / (2 * (1 - cos(A / 180 * M_PI))));
        }
    }

    std::string get_type() override { return "Равнобедренный трегольник"; }

    virtual bool correct() override { return true; }
};