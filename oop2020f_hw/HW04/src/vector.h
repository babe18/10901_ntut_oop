#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
#include<cmath>
class Vector {
public:
  Vector(double v[], int dim) {
    copy(dim, v);
  }
  Vector(Vector const & v){
    copy(v._dim, v._v);
  }

  // destructor
  ~Vector() {
    delete [] _v;
  }

// constant member function
  int dim() const{
    return _dim;
  }

  double & at(int i) const{
    return _v[i-1];
  }

  void subtract(Vector const & v)
  {
    if (v.dim() != dim())
      throw std::string("error: dimension of vectors need to be the same.");
    for(int i =1; i<= _dim; i++)
      at(i) -= v.at(i);
  }

  void add(Vector const & v)
  {
    if (v.dim() != dim())
      throw std::string("error: dimension of vectors need to be the same.");
    for(int i =1; i<= _dim; i++)
      at(i) += v.at(i);
  }

  Vector & operator = (Vector const & u)
  {
    delete [] _v;
    copy(u.dim(), u._v);
    return *this;
  }

  Vector operator - (Vector const & v) const
  {
    if (v.dim() != dim())
      throw std::string("error: dimension of vectors need to be the same.");
    Vector r(*this);
    r.subtract(v);
    return r;
  }

  Vector operator + (Vector const & v) const
  {
    if (v.dim() != dim())
      throw std::string("error: dimension of vectors need to be the same.");
    Vector r(*this);
    r.add(v);
    return r;
  }

  double length() const {
    double dist2 = 0;
    for (int i=1; i<= _dim; ++i)
      dist2 += at(i)*at(i);
    return sqrt (dist2);
  }

private:
  int _dim;
  double * _v;
  void copy(int dim, double v[]){
      _dim = dim;
      _v = new double[_dim];
      for (int  i=0 ; i < _dim ;i++)
        _v[i]=v[i];
  }
};

double distance(Vector const & u, Vector const & v)
{
  return (u-v).length();
}

double area(Vector const & u, Vector const & v, Vector const & w) {
  double a = (v-u).length();
  double b = (w-v).length();
  double c = (u-w).length();

  double s = (a+b+c)/2;

  return sqrt(s*(s-a)*(s-b)*(s-c));

}

double area(Vector a[], int sides)
{
  double sum = 0;
  for(int i = 1; i <= sides - 2; i++){
    sum += area(a[0], a[i], a[i+1]);
  }
  return sum;
}

double perimeter(Vector a[], int sides)
{
  if (sides < 3)
    throw std::string("sides error");
  double perimeter = distance(a[0], a[sides - 1]);
  for(int i = 0; i <= sides - 2; i++){
    perimeter += distance(a[i], a[i+1]);
  }
  return perimeter;
}


#endif
