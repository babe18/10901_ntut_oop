#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include "bubble_sort.h"

class Vector {
public:
  // default constructor
    Vector();
    Vector(double v[], int dim);
    // copy constructor
    Vector(Vector const & v);
    // destructor
    ~Vector();
    // constant member function
    int dim() const;
    double & at(int i) const;
    void subtract(Vector const & v);
    void add(Vector const & v);
    Vector & operator = (Vector const & u);
    Vector operator - (Vector const & v) const;
    Vector operator + (Vector const & v) const;
    double length() const;
    std::string toString() const;
private:
    int _dim;
    double * _v;
    void copy(double v[]);
};

double dot(Vector const & u, Vector const & v);
double area(Vector const & u, Vector const & v, Vector const & w);
double area(Vector a[], int sides);
Vector centroid(Vector vec[], int sides);;
double angle(Vector const & u, Vector const & v);
double distance(Vector const & u, Vector const & v);
double getStandardAngle(Vector vv, Vector c);
double convexPolygonArea(Vector vec[], int sides);

#endif
