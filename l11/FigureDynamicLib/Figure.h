#pragma once

#include <numeric>
#include <string>

#ifdef FIGURELIB_EXPORTS
#define FIGURELIB_API __declspec(dllexport)
#else
#define FIGURELIB_API __declspec(dllimport)
#endif

class Figure {
public:
    //Figure() : _sides(0), _side_length(nullptr), _corner_degree(nullptr) {}
    FIGURELIB_API Figure(unsigned sides);
    FIGURELIB_API Figure(unsigned sides, double* side_length, double* corner_degree);

    FIGURELIB_API ~Figure();

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

FIGURELIB_API
void print_info(Figure* f);