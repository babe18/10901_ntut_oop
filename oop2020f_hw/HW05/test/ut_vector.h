#include <cmath>
#include "../src/vector.h"
#include "../src/bubbleSort.h"

double const epsilon = 0.0001;

TEST(VectorTest, distance1)
{
  double a[]={1, 0, 2};
  double b[]={1, 1, 3};
  Vector x(a, 3);
  Vector y(b, 3);
  ASSERT_NEAR(sqrt(2), distance(x,y),epsilon);
}

TEST(VectorTest, distance2)
{
  double a[]={4, 7, 9};
  double b[]={7, 3, 9};
  Vector x(a, 3);
  Vector y(b, 3);
  ASSERT_NEAR(5, distance(x,y), epsilon);
}

TEST(VectorTest, TriangleArea1)
{
  double a[]={1, 0};
  double b[]={1, 1};
  double c[]={0, 0};
  Vector x(a, 2);
  Vector y(b, 2);
  Vector z(c, 2);
  ASSERT_NEAR(0.5, area(x,y,z),epsilon);
}

TEST(VectorTest, TriangleArea2)
{
  double a[]={5, 0};
  double b[]={5, 5};
  double c[]={0, 5};
  Vector x(a, 2);
  Vector y(b, 2);
  Vector z(c, 2);
  ASSERT_NEAR(12.5, area(x,y,z),epsilon);
}

TEST(VectorTest, TriangleAreaUseArray1)
{
  double a[]={1, 0};
  double b[]={1, 1};
  double c[]={0, 0};
  Vector x(a, 2);
  Vector y(b, 2);
  Vector z(c, 2);
  Vector arr[] = {x, y, z};
  ASSERT_NEAR(0.5, area(arr, 3), epsilon);
}

TEST(VectorTest, TriangleAreaUseArray2)
{
  double a[]={5, 0};
  double b[]={5, 5};
  double c[]={0, 5};
  Vector x(a, 2);
  Vector y(b, 2);
  Vector z(c, 2);
  Vector arr[] = {x, y, z};
  ASSERT_NEAR(12.5, area(arr, 3), epsilon);
}

TEST(VectorTest, QuadrilateralArea)
{
  double a[]={1, 0};
  double b[]={1, 1};
  double c[]={0, 1};
  double d[]={0, 0};
  Vector x(a, 2);
  Vector y(b, 2);
  Vector z(c, 2);
  Vector w(d, 2);
  Vector arr[] = {x, y, z, w};
  ASSERT_NEAR(1, area(arr, 4), epsilon);
}

TEST(VectorTest, PentagonArea){
  double a[]={0, 0};
  double b[]={2, 0};
  double c[]={2, 2};
  double d[]={1, 3};
  double e[]={0, 2};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector x(c, 2);
  Vector y(d, 2);
  Vector z(e, 2);
  Vector arr[] = {u, v, x, y, z};
  ASSERT_NEAR(5, area(arr, 5), epsilon);
}

TEST(VectorTest, TrianglePerimeter1)
{
  double a[]={1, 0};
  double b[]={1, 1};
  double c[]={0, 0};
  Vector x(a, 2);
  Vector y(b, 2);
  Vector z(c, 2);
  Vector arr[] = {x, y, z};
  ASSERT_NEAR(2 + sqrt(2), perimeter(arr, 3), epsilon);
}

TEST(VectorTest, TrianglePerimeter2)
{
  double a[]={5, 0};
  double b[]={5, 5};
  double c[]={0, 5};
  Vector x(a, 2);
  Vector y(b, 2);
  Vector z(c, 2);
  Vector arr[] = {x, y, z};
  ASSERT_NEAR(10 + 5 * sqrt(2), perimeter(arr, 3), epsilon);
}

TEST(VectorTest, QuadrilateralPerimeter)
{
  double a[]={1, 0};
  double b[]={1, 1};
  double c[]={0, 1};
  double d[]={0, 0};
  Vector x(a, 2);
  Vector y(b, 2);
  Vector z(c, 2);
  Vector w(d, 2);
  Vector arr[] = {x, y, z, w};
  ASSERT_NEAR(4, perimeter(arr, 4), epsilon);
}

TEST(VectorTest, PentagonPerimeter){
  double a[]={0, 0};
  double b[]={2, 0};
  double c[]={2, 2};
  double d[]={1, 3};
  double e[]={0, 2};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector x(c, 2);
  Vector y(d, 2);
  Vector z(e, 2);
  Vector arr[] = {u, v, x, y, z};
  ASSERT_NEAR(6 + 2 * sqrt(2), perimeter(arr, 5), epsilon);
}

TEST(PolygonTest, Centroid){
  double a[]={0, 0};
  double b[]={2, 0};
  double c[]={2, 2};
  double d[]={1, 3};
  double e[]={0, 2};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector x(c, 2);
  Vector y(d, 2);
  Vector z(e, 2);
  Vector arr[] = {u, v, x, y, z};
  Vector cent = centroid(arr, 5);
  ASSERT_NEAR(1, cent.at(1), epsilon);
  ASSERT_NEAR(7.0/5.0, cent.at(2), epsilon);
  ASSERT_EQ(2, cent.dim());
}

TEST(PolygonTest, CentroidException){
  double a[]={0, 0};
  double b[]={2, 0};
  double c[]={2, 2, 3};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector x(c, 3);
  Vector arr[] = {u, v, x};
  ASSERT_ANY_THROW(centroid(arr, 5));
}

TEST(PolygonTest, convexPolygonArea){
  double a[]={0, 0};
  double c[]={2, 2};
  double d[]={1, 3};
  double e[]={0, 2};
  double b[]={2, 0};
  double f[]={3, 1};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector w(c, 2);
  Vector x(d, 2);
  Vector y(e, 2);
  Vector z(f, 2);
  Vector arr[] = {u, v, w, x, y, z};
  ASSERT_NEAR(6, area(arr, 6), epsilon);

}

TEST(PolygonTest, convexPolygonAreaException){
  double a[]={0, 0};
  double b[]={2, 0};
  double c[]={2, 2, 3};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector x(c, 3);
  Vector arr[] = {u, v, x};
  ASSERT_ANY_THROW(area(arr, 5));
}
