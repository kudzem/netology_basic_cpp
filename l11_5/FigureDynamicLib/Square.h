#pragma once
#include "Rectangle.h"

//FIGURELIB_API
class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side)
    {}

    std::string get_type() override { return " вадрат"; }
};
