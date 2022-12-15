#pragma once
#include "Parallelogram.h"

//FIGURELIB_API
class Diamond : public Parallelogram {
public:
    Diamond(double a, double A) : Parallelogram(a, a, A)
    {}

    std::string get_type() override { return "Ромб"; }
};