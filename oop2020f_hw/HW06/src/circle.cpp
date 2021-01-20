#include "circle.h"

Circle::Circle (double r):_r(r) {
}

double Circle::area() const
{
    return M_PI * _r * _r;
}
double Circle::perimeter() const
{
    return 2 * _r * M_PI;
}
