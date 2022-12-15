#pragma once
#include "IsoscelesTriangle.h"

class EquilateralTriangle : public IsoscelesTriangle {
public:
    EquilateralTriangle(double side) : IsoscelesTriangle(60, side, IsoscelesTriangleSide::Base)
    {}

    std::string get_type() override { return "Равносторонний трегольник"; }
};
