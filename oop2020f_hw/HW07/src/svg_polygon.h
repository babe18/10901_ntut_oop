#ifndef POLYGON_H
#define POLYGON_H
#include <cmath>
#include "svg_shape.h"

class SvgPolygon : public SvgShape {
public:
    SvgPolygon(std::vector<double *> const & v):SvgShape(), _v(v){}
    std::string toSVG() const {
        std::string svg = "<polygon points=\"";
        for (auto iterator = _v.begin(); iterator != _v.end(); iterator++){
            svg += std::to_string((*iterator)[0]) + " " + std::to_string((*iterator)[1]) + " ";
        }
        svg.pop_back();
        svg += "\" stroke-width=\"" + std::to_string(getStrokeWidth()) + "\" stroke=\"" + getStrokeColor() + "\" fill=\"" + getFillColor() + "\"/>";
        return svg;
    }

private:
    std::vector<double *> _v;
};

#endif
