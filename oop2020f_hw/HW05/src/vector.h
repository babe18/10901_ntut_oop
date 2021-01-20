#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
#include<cmath>
#include<string>
#include "bubbleSort.h"

using namespace std;

class Vector {
public:
  Vector(double v[], int dim) {
    copy(dim, v);
  }
  Vector(Vector const & v){
    copy(v._dim, v._v);
  }
  Vector(){
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

  double dot(Vector input) {
      double result = 0;
                //input.len also works, beacuse
                // input is an object of the same class
      if(_dim != input.dim()){
        throw string("ERROR");
      }
      for(int i=0;i<_dim;i++) {
                              // input.content[i] also works, beacuse
                              // input is an object of the same class
        result += _v[i] * input.at(i+1);
      }
      return result;
    }


  bool larger180(Vector input){
      return (this->at(1)*input.at(2) - this->at(2)*input.at(1))>=0;
    }


  double angle(Vector input){
      double sum1=0,sum2=0;
      sum1 = this->dot(input);
      sum2 = this->length() * input.length();
      if(this->larger180(input)){
        return 360-acos(sum1/sum2)*180/M_PI;
      }
      return acos(sum1/sum2)*180/M_PI;
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

Vector centroid(Vector vec[], int sides)
{
    int dim = vec[0].dim();
    for(int i = 0; i < sides; i++){
        if (vec[i].dim() != dim)
            throw std::string("dimension error.");
    }
    double arr[dim] = {0};
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < sides; j++)
            arr[i] += vec[j].at(i + 1);
        arr[i] = arr[i] / sides;
    }
    return Vector(arr, dim);
}

int dot(Vector const & u, Vector const & v) // call by reference
{
  int sum = 0;
  // for (int i =0; i<v._dim; i++)
  for (int i =1; i<=v.dim(); i++)
    sum += u.at(i)*v.at(i);
  return sum;
}

double angle(Vector const & u, Vector const & v)
{
  return acos(dot(u,v)/(u.length()*v.length()));
}

double getStandardAngle(Vector v){
    double arr[2] = {1, 0};
    Vector standardVector = Vector(arr, 2);
    double angleV = angle(standardVector, v);
    if (v.at(2) > 0)
        return angleV;
    else
        return 2 * M_PI - angleV;
}

class angleComparator{
  private:
    Vector _a;
    Vector _b;
  public:
		angleComparator(){
		}
    angleComparator(Vector &a, Vector &b){
      _a = a;
      _b = b;
    }
    bool operator ()(Vector &u, Vector &v){
      return _b.angle(u-_a)<_b.angle(v-_a);
    }
};

double area(Vector a[], int sides){
	Vector c = centroid(a, sides);
  Vector b = a[0] - c;
	Vector x;
	angleComparator comp(c, b);
  bubbleSort(a, a+sides, comp);

	double area = 0;
  for (int i  = 0; i < (sides - 2); i++){
      area += area(a[0], a[i+1], a[i+2]);
  }
  return area;
}

/*double area(Vector vec[], int sides)
{
  int dim = vec[0].dim();
  for(int i = 0; i < sides; i++){
      if (vec[i].dim() != dim)
          throw std::string("dimension error.");
  }

  Vector cent = centroid(vec, sides);
  for(int i = 0; i < sides; i++){
      vec[i] = vec[i] - cent;
  }
  bubbleSort(vec, vec + sides, [](Vector v, Vector u){
      return getStandardAngle(v) < getStandardAngle(u);
  });

  double sum = 0;
  for(int i = 1; i <= sides - 2; i++){
    sum += area(vec[0], vec[i], vec[i+1]);
  }
  return sum;
}*/

#endif
