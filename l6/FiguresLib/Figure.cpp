#include <iostream>

#include "Figure.h"

std::string ShortSideNames[] = { "a", "b", "c", "d", "e", "f" };
std::string ShortCornerNames[] = { "A", "B", "C", "D", "E", "F" };


Figure::Figure(unsigned sides) : _sides(sides)
{
    _side_length = new double[_sides];
    _corner_degree = new double[_sides];
}

Figure::Figure(unsigned sides, double* side_length, double* corner_degree) : Figure(sides) {
    for (unsigned s = 0; s < _sides; ++s) {
        _side_length[s] = side_length[s];
        _corner_degree[s] = corner_degree[s];
    }
}

Figure::~Figure() {
    delete[] _side_length;
    delete[] _corner_degree;
}

bool
Figure::correct() {
    if (_sides < 3) return true;
    double corner_sum = std::accumulate(_corner_degree, _corner_degree + _sides, 0);
    if (corner_sum == (_sides - 2) * 180) return true;
    return false;
}

double 
Figure::get_side_length(unsigned side_idx) {
    if (!_side_length) return -1;
    if (side_idx >= _sides) return -1;
    return _side_length[side_idx];
}

double 
Figure::get_corner(unsigned corner_idx) {
    if (!_corner_degree) return -1;
    if (corner_idx >= _sides) return -1;
    return _corner_degree[corner_idx];
}

void
print_info(Figure* f) {
    std::cout << f->get_type() << ":" << std::endl;

    std::cout << (f->correct() ? "Правильная" : "Неправильная") << std::endl;

    std::cout << "Количество сторон : " << f->get_sides() << std::endl;
    std::cout << "Стороны: ";
    const unsigned sides = f->get_sides();
    for (unsigned i = 0; i < sides; ++i) {
        std::cout << ShortSideNames[i] << " = " << f->get_side_length(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Углы: ";
    for (unsigned i = 0; i < sides; ++i) {
        std::cout << ShortCornerNames[i] << " = " << f->get_corner(i) << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
};