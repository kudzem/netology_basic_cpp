#pragma once
#include "Triangle.h"
#include <math.h>
#define _USE_MATH_DEFINES

enum class RightTriangleSide {
    AdjacentKatet,
    OppositeKatet,
    Hypotenuse
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double A, double hypotenuse) : Triangle()
    {
        _side_length[2] = hypotenuse;
        _corner_degree[0] = A;
        _corner_degree[1] = 90 - A;
        _corner_degree[2] = 90;
        _side_length[0] = hypotenuse * cos(A / 180 * M_PI);
        _side_length[1] = hypotenuse * sin(A / 180 * M_PI);
    }

    std::string get_type() override { return "Прямоугольный трегольник"; }

    virtual bool correct() override { return true; }
};
