#pragma once
#include "Parallelogram.h"

//FIGURELIB_API
class Rectangle : public Parallelogram {
public:
    Rectangle(double a, double b) : Parallelogram(a, b, 90)
    {}

    std::string get_type() override { return "Прямоугольник"; }
};
