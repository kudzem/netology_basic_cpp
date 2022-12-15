#pragma once
#include "Figure.h"

class Quad : public Figure {
protected:
    Quad() : Figure(4) {}
public:
    FIGURELIB_API Quad(double* side_length, double* corner_degree) : Figure(4, side_length, corner_degree) {}

    FIGURELIB_API std::string get_type() override { return "Четырехугольник"; }

    FIGURELIB_API
    virtual bool correct() override {
        double corner_sum = std::accumulate(_corner_degree, _corner_degree + get_sides(), 0);
        if (corner_sum != 360) return false;
        return true;
    }
};
