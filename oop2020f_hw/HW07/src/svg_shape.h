#ifndef SHAPE_H
#define SHAPE_H

class SvgShape {
public:
    SvgShape(){
        _fillColor = "black";
        _strokeColor = "black";
        _strokeWidth = 0;
    }
    void setFillColor(std::string fillColor) {_fillColor = fillColor;}
    void setStroke(double strokeWidth, std::string strokeColor) {
        _strokeWidth = strokeWidth;
        _strokeColor = strokeColor;
    }
    virtual std::string toSVG() const = 0;
    virtual ~SvgShape() {}
protected:
    double getStrokeWidth() const {
        return _strokeWidth;
    }
    std::string getFillColor() const {
        return _fillColor;
    }
    std::string getStrokeColor() const {
        return _strokeColor;
    }
private:
    double _strokeWidth;
    std::string _fillColor, _strokeColor;
};

void setSvgShapeStyle(SvgShape * shape, double strokeWidth, std::string strokeColor, std::string fillColor){
    shape->setStroke(strokeWidth, strokeColor);
    shape->setFillColor(fillColor);
}

std::string makeSvgOutput(int width, int height, std::vector<SvgShape *> const & shape){
    std::string svgOutput = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" + std::to_string(width) + "\" height=\"" + std::to_string(height) + "\" viewBox=\"0 0 100 100\">";
    for (auto iterator = shape.begin(); iterator != shape.end(); iterator++){
        svgOutput += (**iterator).toSVG();
    }
    svgOutput += "</svg>";
    return svgOutput;
}

#endif
