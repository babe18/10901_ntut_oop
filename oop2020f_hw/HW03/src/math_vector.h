#include <cmath>

using namespace std;

class MathVector {
	double * _vec;
	int _dim;

public:

  MathVector(){
    _dim = 0;
    _vec = new double[_dim];
  }

  MathVector(double a[], int dim){
    _dim = dim;
    _vec = new double[_dim];
    for( int i = 0; i < _dim; i++){
      _vec[i] = a[i];
    }
  }

  double component(int index) {
    return _vec[index-1];
  }

  bool isZero() {
    if(_dim == 0) {
      return true;
    } else {
      return false;
    }
  }

  double length() {
    double accumulate = 0;
    for(int i = 0;i < _dim;i++) {
      accumulate += pow(_vec[i], 2);
    }
    return sqrt (accumulate);
  }

  int getDim() {
    return _dim;
  }
};
