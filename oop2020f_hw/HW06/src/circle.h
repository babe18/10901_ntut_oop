#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <cmath>

class Circle : public Shape{
public:
  Circle (double r);
  double area() const;
  double perimeter() const;
private:
  double _r;
};


#endif
