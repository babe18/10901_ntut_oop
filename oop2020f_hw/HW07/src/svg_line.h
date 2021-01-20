#ifndef LINE_H
#define LINE_H
#include <cmath>
#include "svg_shape.h"
class SvgLine : public SvgShape {
public:
    SvgLine(double x1, double y1, double x2, double y2):SvgShape(), _x1(x1), _y1(y1), _x2(x2), _y2(y2){}
    std::string toSVG() const {
        std::string svg = "<line x1=\"" + std::to_string(_x1) + "\" y1=\"" + std::to_string(_y1) + "\" x2=\"" + std::to_string(_x2) + "\" y2=\"" + std::to_string(_y2) + "\" stroke-width=\"" + std::to_string(getStrokeWidth()) + "\" stroke=\"" + getStrokeColor() + "\" fill=\"" + getFillColor() + "\"/>";
        return svg;
    }

private:
    double _x1, _y1, _x2, _y2;
};

#endif
