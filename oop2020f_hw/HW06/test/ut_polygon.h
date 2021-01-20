#include "../src/vector.h"
#include "../src/bubble_sort.h"
#include "../src/polygon.h"
#include "../src/circle.h"
#include "../src/shape.h"
#include <cmath>

double const epsilon = 0.0001;

TEST(ShapeTest, Polygon){
  double a[]={0, 0};
  double b[]={0, 1};
  double c[]={1, 1};
  double d[]={1, 0};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector w(c, 2);
  Vector x(d, 2);
  Vector arr[] = {u, v, w, x};
  Polygon * poly = new Polygon(arr, 4);
  ASSERT_NEAR(1, poly->area(), epsilon);
  ASSERT_NEAR(4, poly->perimeter(), epsilon);

}

TEST(ShapeTest, Circle){
    Circle * c = new Circle(2.5);
    ASSERT_NEAR(6.25 * M_PI, c->area(), epsilon);
    ASSERT_NEAR(5 * M_PI, c->perimeter(), epsilon);
}

TEST(ShapeTest, Shape){
    Shape * c = new Circle(6);
    ASSERT_NEAR(6 * 6 * M_PI, c->area(), epsilon);
    double a[]={0, 0};
    double b[]={0, 2};
    double d[]={2, 0};
    Vector u(a, 2);
    Vector v(b, 2);
    Vector w(d, 2);
    Vector arr[] = {u, v, w};
    Polygon * poly = new Polygon(arr, 3);
    ASSERT_NEAR(2, poly->area(), epsilon);
}

TEST(FindTest, FindAll) {
    double a[]={0, 0};
    double b[]={2, 0};
    double c[]={3, 1};
    double d[]={3, 3};
    double e[]={1, 3};
    double f[]={0, 2};
    Vector u(a, 2);
    Vector v(b, 2);
    Vector w(c, 2);
    Vector x(d, 2);
    Vector y(e, 2);
    Vector z(f, 2);
    Vector arr1[] = {u, v, w};//1
    Vector arr2[] = {u, v, w, x};//4
    Vector arr3[] = {u, v, w, x, y};//7
    Vector arr4[] = {u, v, w, x, y, z};//8
    std::vector<Shape *> vec;
    vec.push_back(new Polygon(arr1, 3));
    vec.push_back(new Circle(2));
    vec.push_back(new Polygon(arr2, 4));
    vec.push_back(new Polygon(arr3, 5));
    vec.push_back(new Circle(0.5));
    vec.push_back(new Circle(1.5));
    vec.push_back(new Polygon(arr4, 6));
    vec.push_back(new Circle(1));
    std::vector<Shape *> result = findAll(vec.begin(), vec.end(), [](Shape *s){
        return s->area() > 2 && s->area() < 7.5;
    });
    ASSERT_EQ(4 , result.size());
    ASSERT_NEAR(4, result[0]->area(), epsilon);
    ASSERT_NEAR(7, result[1]->area(), epsilon);
    ASSERT_NEAR(2.25 * M_PI, result[2]->area(), epsilon);
    ASSERT_NEAR(M_PI, result[3]->area(), epsilon);
}
