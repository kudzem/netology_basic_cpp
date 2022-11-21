#include <iostream>

class Figure {
public:
    Figure() : _sides(0) {}
    Figure(unsigned sides) : _sides(sides) {}
    unsigned get_sides() { return _sides; }
private:
    unsigned _sides;
};

class Triangle : public Figure {
public:
    Triangle() : Figure(3) {}
};

class Quad : public Figure {
public:
    Quad() : Figure(4) {}
};

int main()
{
    Figure f;
    std::cout << "Unknown figure has " << f.get_sides() << " sides" << std::endl;

    Triangle t;
    std::cout << "Triangle figure has " << t.get_sides() << " sides" << std::endl;

    Quad q;
    std::cout << "Quadrilateral figure has " << q.get_sides() << " sides" << std::endl;

    Figure* fq = &q;
    std::cout << "Quadrilateral figure has " << fq->get_sides() << " sides anyway" << std::endl;
}


