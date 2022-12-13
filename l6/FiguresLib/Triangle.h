#pragma once
#include "Figure.h"
#include <math.h>

#define _USE_MATH_DEFINES


class Triangle : public Figure {
protected:
    Triangle() : Figure(3)
    {}
public:
    Triangle(double* side_length, double* corner_degree) : Figure(3, side_length, corner_degree)
    {}

    Triangle(unsigned* side_length);

    std::string get_type() override { return "Трегольник"; }

    virtual bool correct() override;
};
