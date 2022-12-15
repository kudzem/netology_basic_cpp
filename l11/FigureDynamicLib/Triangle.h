#pragma once
#include "Figure.h"
#include <math.h>

#define _USE_MATH_DEFINES


class Triangle : public Figure {
protected:
    Triangle() : Figure(3)
    {}
public:
    FIGURELIB_API
    Triangle(double* side_length, double* corner_degree) : Figure(3, side_length, corner_degree)
    {}

    FIGURELIB_API
    Triangle(unsigned* side_length);

    FIGURELIB_API
    std::string get_type() override { return "Трегольник"; }

    FIGURELIB_API
    virtual bool correct() override;
};
