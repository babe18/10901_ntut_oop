#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
#include "vector.h"
#include "dot.h"
class Polygon : public Shape
{
public:
  Polygon(Vector v[], int sides);
  ~Polygon();
  double area() const;
  double perimeter() const;
private:
  Vector *_v;
  int _sides;
};
#endif
