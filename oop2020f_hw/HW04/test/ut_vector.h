#include <cmath>
#include "../src/vector.h"

double const epsilon = 0.0001;

TEST(VectorTest, Subtraction1)
{
  double a[]={1, 0, 2};
  double b[]={1, 1, 3};
  Vector x(a, 3);
  Vector y(b, 3);
  Vector z = x - y;
  ASSERT_NEAR(0, z.at(1), epsilon);
  ASSERT_NEAR(-1, z.at(2), epsilon);
  ASSERT_NEAR(-1, z.at(3), epsilon);
  ASSERT_EQ(3, z.dim());
}

TEST(VectorTest, Subtraction2)
{
  double a[]={1, 7, 2};
  double b[]={10, 1, 3};
  Vector x(a, 3);
  Vector y(b, 3);
  Vector z = x - y;
  ASSERT_NEAR(-9, z.at(1), epsilon);
  ASSERT_NEAR(6, z.at(2), epsilon);
  ASSERT_NEAR(-1, z.at(3), epsilon);
  ASSERT_EQ(3, z.dim());
}

TEST(VectorTest, SubtractionException)
{
  double a[]={1, 7, 2};
  double b[]={10, 1, 3, 4};
  Vector x(a, 3);
  Vector y(b, 4);
  ASSERT_ANY_THROW(x - y);
}

TEST(VectorTest, Subtract)
{
  double a[]={1, 0, 2};
  double b[]={1, 1, 3};
  Vector x(a, 3);
  Vector y(b, 3);
  x.subtract(y);
  ASSERT_NEAR(0, x.at(1), epsilon);
  ASSERT_NEAR(-1, x.at(2), epsilon);
  ASSERT_NEAR(-1, x.at(3), epsilon);
}

TEST(VectorTest, Subtract2)
{
  double a[]={1, 7, 2};
  double b[]={10, 1, 3};
  Vector x(a, 3);
  Vector y(b, 3);
  x.subtract(y);
  ASSERT_NEAR(-9, x.at(1), epsilon);
  ASSERT_NEAR(6, x.at(2), epsilon);
  ASSERT_NEAR(-1, x.at(3), epsilon);
}

TEST(VectorTest, SubtractException)
{
  double a[]={1, 7, 2};
  double b[]={10, 1, 3, 4};
  Vector x(a, 3);
  Vector y(b, 4);
  ASSERT_ANY_THROW(x.subtract(y));
}

TEST(VectorTest, Addition1)
{
  double a[]={1, 0, 2};
  double b[]={1, 1, 3};
  Vector x(a, 3);
  Vector y(b, 3);
  Vector z = x + y;
  ASSERT_NEAR(2, z.at(1), epsilon);
  ASSERT_NEAR(1, z.at(2), epsilon);
  ASSERT_NEAR(5, z.at(3), epsilon);
  ASSERT_EQ(3, z.dim());
}

TEST(VectorTest, Addition2)
{
  double a[]={1, 7, 2};
  double b[]={10, 1, 3};
  Vector x(a, 3);
  Vector y(b, 3);
  Vector z = x + y;
  ASSERT_NEAR(11, z.at(1), epsilon);
  ASSERT_NEAR(8, z.at(2), epsilon);
  ASSERT_NEAR(5, z.at(3), epsilon);
  ASSERT_EQ(3, z.dim());
}

TEST(VectorTest, AdditionException)
{
  double a[]={1, 7, 2};
  double b[]={10, 1, 3, 4};
  Vector x(a, 3);
  Vector y(b, 4);
  ASSERT_ANY_THROW(x + y);
}

TEST(VectorTest, Add1)
{
  double a[]={1, 0, 2};
  double b[]={1, 1, 3};
  Vector x(a, 3);
  Vector y(b, 3);
  x.add(y);
  ASSERT_NEAR(2, x.at(1), epsilon);
  ASSERT_NEAR(1, x.at(2), epsilon);
  ASSERT_NEAR(5, x.at(3), epsilon);
}

TEST(VectorTest, Add2)
{
  double a[]={1, 7, 2};
  double b[]={10, 1, 3};
  Vector x(a, 3);
  Vector y(b, 3);
  x.add(y);
  ASSERT_NEAR(11, x.at(1), epsilon);
  ASSERT_NEAR(8, x.at(2), epsilon);
  ASSERT_NEAR(5, x.at(3), epsilon);
}

TEST(VectorTest, AddException)
{
  double a[]={1, 7, 2};
  double b[]={10, 1, 3, 4};
  Vector x(a, 3);
  Vector y(b, 4);
  ASSERT_ANY_THROW(x.add(y));
}

TEST(VectorTest, CopyAssignment1)
{
  double a[]={1, 0, 2};
  double b[]={1, 1, 3};
  double c[]={0, 0, 0};
  Vector x(a, 3);
  Vector y(b, 3);
  Vector z(c, 3);
  z = x = y;
  ASSERT_EQ(1, z.at(1));
  ASSERT_EQ(1, z.at(2));
  ASSERT_EQ(3, z.at(3));
  ASSERT_EQ(1, x.at(1));
  ASSERT_EQ(1, x.at(2));
  ASSERT_EQ(3, x.at(3));
}

TEST(VectorTest, CopyAssignment2)
{
  double a[]={1, 20, 2};
  double b[]={11, 1, 3};
  Vector x(a, 3);
  Vector y(b, 3);
  x = y;
  ASSERT_EQ(11, x.at(1));
  ASSERT_EQ(1, x.at(2));
  ASSERT_EQ(3, x.at(3));
}

TEST(VectorTest, CopyAssignment3)
{
  double a[]={1, 20, 2};
  double b[]={11, 1, 3, 7};
  Vector x(a, 3);
  Vector y(b, 4);
  x = y;
  ASSERT_EQ(11, x.at(1));
  ASSERT_EQ(1, x.at(2));
  ASSERT_EQ(3, x.at(3));
  ASSERT_EQ(7, x.at(4));
}
