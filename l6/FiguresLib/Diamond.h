#pragma once
#include "Parallelogram.h"

class Diamond : public Parallelogram {
public:
    Diamond(double a, double A) : Parallelogram(a, a, A)
    {}

    std::string get_type() override { return "Ромб"; }
};