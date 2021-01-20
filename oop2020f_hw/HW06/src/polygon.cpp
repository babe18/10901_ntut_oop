#include "polygon.h"

Polygon::Polygon(Vector v[], int sides):_sides(sides)
{
  _v = new Vector[_sides];
  for (int  i=0 ; i < _sides ;i++)
  _v[i]=v[i];
}

Polygon::~Polygon()
{
  delete _v;
}

double Polygon::area() const
{
    Vector cent = centroid(_v, _sides);
    bubbleSort(_v, _v + _sides, [cent](Vector v, Vector u){
        return getStandardAngle(v, cent) < getStandardAngle(u, cent);
    });

    double sum = 0;
    for(int i = 1; i <= _sides-2; i++){
        sum += ::area(_v[0], _v[i], _v[i+1]);
    }

    return sum;
}
double Polygon::perimeter() const
{
    Vector cent = centroid(_v, _sides);
    bubbleSort(_v, _v + _sides, [cent](Vector v, Vector u){
        return getStandardAngle(v, cent) < getStandardAngle(u, cent);
    });
    double sum = 0;
    for(int i = 0; i <= _sides - 2; i++){
        sum += distance(_v[i], _v[i + 1]);
    }
    sum += distance(_v[_sides - 1], _v[0]);
    return sum;
}
