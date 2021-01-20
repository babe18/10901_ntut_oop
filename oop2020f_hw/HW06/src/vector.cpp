#include "vector.h"

Vector::Vector():_dim(-1), _v(nullptr)
{

}

Vector::Vector(double v[], int dim): _dim(dim), _v(nullptr)
{
    copy(v);
}

// copy constructor
Vector::Vector(Vector const & v): _dim(v._dim), _v(nullptr)
{
    copy(v._v);
}

// destructor
Vector::~Vector()
{
    if (_v != nullptr)
        delete [] _v;
}

// constant member function
int Vector::dim() const{
    return _dim;
}

double & Vector::at(int i) const
{
    return _v[i-1];
}

void Vector::subtract(Vector const & v)
{
    for(int i =1; i<= _dim; i++)
        at(i) -= v.at(i);
}

void Vector::add(Vector const & v)
{
    for(int i =1; i<= _dim; i++)
        at(i) += v.at(i);
}

Vector & Vector::operator = (Vector const & u)
{
    _dim = u.dim();
    copy(u._v);
    return *this;
}

Vector Vector::operator - (Vector const & v) const
{
    if (v.dim() != dim())
        throw std::string("error: dimension of vectors need to be the same.");
    Vector r(*this);
    r.subtract(v);
    return r;
}

Vector Vector::operator + (Vector const & v) const
{
    if (v.dim() != dim())
        throw std::string("error: dimension of vectors need to be the same.");
    Vector r(*this);
    r.add(v);
    return r;
}

double Vector::length() const
{
    double dist2 = 0;
    for (int i=1; i<= _dim; ++i)
        dist2 += at(i)*at(i);
    return sqrt (dist2);
}

std::string Vector::toString() const {
    std::stringstream ss;
    ss << "(";
    for (int i = 1; i < _dim; i++) {
        ss << at(i) << ", ";
    }
    ss << at(_dim) << ")";
    return ss.str();
}

void Vector::copy(double v[])
{
if(_v != nullptr)
    delete [] _v;
_v = new double[_dim];
for (int  i=0 ; i < _dim ;i++)
    _v[i]=v[i];
}

double dot(Vector const & u, Vector const & v) // call by reference
{
  double sum = 0;
  // for (int i =0; i<v._dim; i++)
  for (int i =1; i<=v.dim(); i++)
    sum += u.at(i)*v.at(i);
  return sum;
}

double area(Vector const & u, Vector const & v, Vector const & w) {
  double a = (v-u).length();
  double b = (w-v).length();
  double c = (u-w).length();

  double s = (a+b+c)/2;

  return sqrt(s*(s-a)*(s-b)*(s-c));

}

double area(Vector a[], int sides){
  double sum = 0;
  for(int i = 1; i <= sides-2; i++){
    sum += area(a[0], a[i], a[i+1]);
  }

  return sum;
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

double angle(Vector const & u, Vector const & v)
{
  return acos(dot(u,v)/(u.length()*v.length()));
}

double distance(Vector const & u, Vector const & v)
{
  return (u-v).length();
}

double getStandardAngle(Vector vv, Vector c){
    Vector v = vv - c;
    double arr[2] = {1, 0};
    Vector standardVector = Vector(arr, 2);
    double angleV = angle(standardVector, v);
    if (v.at(2) > 0)
        return angleV;
    else
        return 2 * M_PI - angleV;
}

double convexPolygonArea(Vector vec[], int sides)
{
    int dim = vec[0].dim();
    for(int i = 0; i < sides; i++){
        if (vec[i].dim() != dim)
            throw std::string("dimension error.");
    }

    Vector cent = centroid(vec, sides);
    bubbleSort(vec, vec + sides, [cent](Vector v, Vector u){
        return getStandardAngle(v, cent) < getStandardAngle(u, cent);
    });
    return area(vec, sides);
}
