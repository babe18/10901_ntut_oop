#ifndef CIRCLE
#define CIRCLE
#include <cmath>
#include "shape.h"
#include "vector.h"
#include "convexPolygon.h"
#include <fstream>      // std::ifstream
#include <string>

using namespace std;

// Dervied class of shape class
// Circle inherets Shape
class Circle : public Shape {
// **public** inheritance makes public members of the base class public in the derived class, and the protected members of the base class remain protected in the derived class.
// **protected** inheritance makes the public and protected members of the base class protected in the derived class.
// **private** inheritance makes the public and protected members of the base class private in the derived class.
private:
  double _radius;
  mathVector _point;
public:
  Circle() : _radius(0){
    //cout << "Constructor in circle" << endl;
    _point = mathVector();
  //  _radius = 0;
  }
  Circle(double radius, mathVector point, string name = "anonymous") : Shape(name){ //constructor initialization list
    _radius = radius;
    _point = point;
  }
  ~Circle() override {
    //cout << "Circle deconstructor" << endl;
  }
  double getPrimeter() const override {
    return 2*_radius*M_PI;
  }
  double getArea() const override {
    return _radius*_radius*M_PI;
  }
  void changeNameTo(string input) override {
    _name = input;
  }
  string toString() const {
    stringstream ss;
    ss << "Circle " << "{\n" << _name << "\n" << _point << "\n" << _radius <<"\n" <<"}";
    return ss.str();
  }
  void fromString(stringstream &s) override{
    string type;
    char c;
    s >> type >> c;
    s >> _name;
    s >> _point;
    s >> _radius >> c;
    //cout << c << endl;
    //ss << "Circle " << "{\n" << "Big" << "\n" << "(2,5,5)" << "\n" << 10 << "\n" <<"}";
    //double x = 0;
    //cin >> x;
  }
  mathVector getPoint() const{
    return _point;
  }
};

// we still have some problems with ss
// please fix it
vector<Shape *> objectsFromFile(string fileName) {
   ifstream ifs(fileName);
   vector<Shape *> result;
   string line;
   stringstream ss;
   while(!ifs.eof()) {
     getline(ifs, line);
     ss << line;
   }
   int num = 0;
   ss >> num;
   string type;
   char c;
   for(int i = 0;i<num;i++){
     ss >> type >> c;

     streampos pos = ss.tellg();
     pos -= (type.length() + 2);
     ss.seekg(pos);

     Shape *obj;
     if(type == "Circle") {
       obj = new Circle();
     }else if(type == "Polygon") {
       obj = new Polygon();
     }
     obj->fromString(ss);
     result.push_back(obj);
   }
   return result;
}
#endif
