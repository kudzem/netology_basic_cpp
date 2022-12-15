#pragma once
#include "Rectangle.h"

//FIGURELIB_API
class Square : public Rectangle {
public:
    FIGURELIB_API Square(double side) : Rectangle(side, side)
    {}

    FIGURELIB_API std::string get_type() override { return " вадрат"; }
};
