#include <list>
#include <clocale>
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Square.h"
#include "Diamond.h"

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

    Triangle t(tl, tc);
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

    Quad q(ql, qc);
    all_figures.push_back(&q);

    Parallelogram p(4, 2, 15);
    all_figures.push_back(&p);

    Rectangle r(4, 3);
    all_figures.push_back(&r);

    Square s(4);
    all_figures.push_back(&s);

    Diamond d(4, 60);
    all_figures.push_back(&d);

    for (auto f : all_figures) {
        print_info(f);
    }

}