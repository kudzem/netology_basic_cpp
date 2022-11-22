#include <iostream>
#include <list>
#include <numeric>


# define M_PI          3.141592653589793238462643383279502884L /* pi */

enum class FigureType {
    Unknown,
    Arbitrary,
    Triangle,
    RightTriangle,
    IsoscelesTriangle,
    EquilateralTriangle,
    Quad,
    Parallelogram,
    Rectangle,
    Square,
    Diamond
};

enum class RightTriangleSide {
    AdjacentKatet,
    OppositeKatet,
    Hypotenuse
};

enum class IsoscelesTriangleSide {
    Thigh,
    Base
};

std::string FiguresTypesStr[] = { "Неизвестно",
                                  "Произвольная фигура",
                                  "Трегольник",
                                  "Прямоугольный трегольник",
                                  "Равнобедренный треугольник",
                                  "Равносторонний треугольник",
                                  "Четырехугольник",
                                  "Паралеллограмм",
                                  "Прямоугольник",
                                  "Квадрат",
                                  "Ромб" };

std::string ShortSideNames[] = { "a", "b", "c", "d", "e", "f"};
std::string ShortCornerNames[] = { "A", "B", "C", "D", "E", "F" };

class Figure {
public:
    Figure() : _sides(0), _side_length(nullptr), _corner_degree(nullptr), _type(FigureType::Unknown)
    {
    }

    Figure(unsigned sides) : _sides(sides), _type(FigureType::Arbitrary)
    {
        _side_length = new double[_sides];
        _corner_degree = new double[_sides];
    }

    Figure(unsigned sides, double* side_length, double* corner_degree) : Figure(sides) {
        for (unsigned s = 0; s < _sides; ++s) {
            _side_length[s] = side_length[s];
            _corner_degree[s] = corner_degree[s];
        }
    }

    ~Figure() { 
        delete[] _side_length; 
        delete[] _corner_degree; 
    }

    unsigned get_sides() const { return _sides; }
    virtual FigureType get_type() { return FigureType::Arbitrary; }

    virtual bool correct() { 
        if (_sides < 3) return true;
        double corner_sum = std::accumulate(_corner_degree, _corner_degree + _sides, 0);
        if (corner_sum == (_sides - 2) * 180) return true;
        return false;
    }

    double get_side_length(unsigned side_idx) {
        if (!_side_length) return -1;
        if (side_idx >= _sides) return -1;
        return _side_length[side_idx];
    }

    double get_corner(unsigned corner_idx) {
        if (!_corner_degree) return -1;
        if (corner_idx >= _sides) return -1;
        return _corner_degree[corner_idx];
    }

private:
    unsigned _sides;
    FigureType _type;

protected:
    double* _side_length;
    double* _corner_degree;
};

class Triangle : public Figure {
protected:
    Triangle() : Figure(3)
    {}
public:
    Triangle(double* side_length, double* corner_degree) : Figure(3, side_length, corner_degree)
    {}

    Triangle(unsigned* side_length) : Triangle()
    {
        double a, b, c;
        a = _side_length[0];
        b = _side_length[1];
        c = _side_length[2];
        _corner_degree[0] = acos((a * a + c * c - b * b) / 2 * a * c);
        _corner_degree[1] = acos((a * a - c * c + b * b) / 2 * a * c);
        _corner_degree[2] = acos((c * c + b * b - a * a) / 2 * a * c);
    }

    FigureType get_type() override { return FigureType::Triangle; }

    virtual bool correct() override {
        double corner_sum = std::accumulate(_corner_degree, _corner_degree + get_sides(), 0);
        if(corner_sum != 180) return false;
        return true;
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double A, double hypotenuse) : Triangle()
    {
        _side_length[2] = hypotenuse;
        _corner_degree[0] = A;
        _corner_degree[1] = 90 - A;
        _corner_degree[2] = 90;
        _side_length[0] = hypotenuse * cos(A/180*M_PI);
        _side_length[1] = hypotenuse * sin(A/180 * M_PI);
    }

    FigureType get_type() override { return FigureType::RightTriangle; }

    virtual bool correct() override { return true; }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double A, double side, IsoscelesTriangleSide sideType) : Triangle()
    {
        _corner_degree[0] = A;
        _corner_degree[1] = (180 - A) / 2;
        _corner_degree[2] = _corner_degree[1];

        if (sideType == IsoscelesTriangleSide::Thigh) {
            _side_length[0] = _side_length[1] = side;
            _side_length[2] = sqrt(2 * side * side * (1 - cos(A / 180 * M_PI)));
        }
        else if (sideType == IsoscelesTriangleSide::Base) {
            _side_length[2] = side;
            _side_length[0] = _side_length[1] = sqrt(side * side / (2 * (1 - cos(A / 180 * M_PI))));
        }
    }

    FigureType get_type() override { return FigureType::IsoscelesTriangle; }

    virtual bool correct() override { return true; }
};

class EquilateralTriangle : public IsoscelesTriangle {
public:
    EquilateralTriangle(double side) : IsoscelesTriangle(60, side, IsoscelesTriangleSide::Base)
    {}

    FigureType get_type() override { return FigureType::EquilateralTriangle; }
};

class Quad : public Figure {
protected:
    Quad() : Figure(4) {}
public:
    Quad(double* side_length, double* corner_degree) : Figure(4, side_length, corner_degree) {}

    FigureType get_type() override { return FigureType::Quad; }

    virtual bool correct() override {
        double corner_sum = std::accumulate(_corner_degree, _corner_degree + get_sides(), 0);
        if (corner_sum != 360) return false;
        return true;
    }
};

class Parallelogram : public Quad {
public:
    Parallelogram(double a, double b, double A) : Quad()
    {
        _side_length[0] = _side_length[2] = a;
        _side_length[1] = _side_length[3] = b;
        _corner_degree[0] = _corner_degree[2] = A;
        _corner_degree[1] = _corner_degree[3] = 180 - A;
    }

    FigureType get_type() override { return FigureType::Parallelogram; }

    virtual bool correct() override { return true; }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(double a, double b) : Parallelogram(a,b,90)
    {}

    FigureType get_type() override { return FigureType::Rectangle; }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side)
    {}

    FigureType get_type() override { return FigureType::Square; }
};

class Diamond : public Parallelogram {
public:
    Diamond(double a, double A) : Parallelogram(a, a, A)
    {}

    FigureType get_type() override { return FigureType::Diamond; }
};

void print_info(Figure* f) {
    std::cout << FiguresTypesStr[static_cast<unsigned>(f->get_type())] << ":" << std::endl;

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

int main()
{
    std::list<Figure*> all_figures;
    setlocale(LC_ALL, "Russian");

    Figure f;
    all_figures.push_back(&f);

    double fl[] = { 2,3,4,5,6 };
    double fc[] = { 36,60,84,200,234 };

    Figure fa(5, fl, fc);
    all_figures.push_back(&fa);

    double tl[] = { 2,3,4 };
    double tc[] = { 36,60,83 };

    Triangle t(tl,tc);
    all_figures.push_back(&t);

    double ql[] = { 2,3,4,1 };
    double qc[] = { 56,80,104,120 };

    RightTriangle rt(30, 30);
    all_figures.push_back(&rt);

    IsoscelesTriangle it(10, 30, IsoscelesTriangleSide::Thigh);
    all_figures.push_back(&it);

    IsoscelesTriangle it2(10, 5.23, IsoscelesTriangleSide::Base);
    all_figures.push_back(&it2);

    EquilateralTriangle et(13);
    all_figures.push_back(&et);

    Quad q(ql,qc);
    all_figures.push_back(&q);

    Parallelogram p(4,2,15);
    all_figures.push_back(&p);

    Rectangle r(4,3);
    all_figures.push_back(&r);

    Square s(4);
    all_figures.push_back(&s);

    Diamond d(4, 60);
    all_figures.push_back(&d);

    for (auto f : all_figures) {
        print_info(f);
    }

}


