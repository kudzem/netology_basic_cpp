#pragma once
#include "Quad.h"

//FIGURELIB_API
class Parallelogram : public Quad {
public:
    Parallelogram(double a, double b, double A) : Quad()
    {
        _side_length[0] = _side_length[2] = a;
        _side_length[1] = _side_length[3] = b;
        _corner_degree[0] = _corner_degree[2] = A;
        _corner_degree[1] = _corner_degree[3] = 180 - A;
    }

    std::string get_type() override { return "ֿאנאכוככמדנאלל"; }

    virtual bool correct() override { return true; }
};