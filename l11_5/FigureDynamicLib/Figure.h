#pragma once

#include <numeric>
#include <string>

class Figure {
public:
    //Figure() : _sides(0), _side_length(nullptr), _corner_degree(nullptr) {}
    Figure(unsigned sides);
    Figure(unsigned sides, double* side_length, double* corner_degree);

    ~Figure();

    unsigned get_sides() const { return _sides; }
    virtual std::string get_type() { return "Произвольная фигура"; }

    virtual bool correct();
    double get_side_length(unsigned side_idx);
    double get_corner(unsigned corner_idx);

private:
    unsigned _sides;

protected:
    double* _side_length;
    double* _corner_degree;
};

void print_info(Figure* f);