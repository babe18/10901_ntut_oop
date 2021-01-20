#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>
#include "svg_shape.h"

class SvgCircle : public SvgShape {
public:
    SvgCircle(double x, double y, double r):SvgShape(), _x(x), _y(y), _r(r){}
    std::string toSVG() const {
        std::string svg = "<circle cx=\"" + std::to_string(_x) + "\" cy=\"" + std::to_string(_y) + "\" r=\"" + std::to_string(_r) + "\" stroke-width=\"" + std::to_string(getStrokeWidth()) + "\" stroke=\"" + getStrokeColor() + "\" fill=\"" + getFillColor() + "\"/>";
        return svg;
    }

private:
    double _x, _y, _r;
};

#endif
