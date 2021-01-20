#ifndef _UT_POLYNOMIAL_H_
#define _UT_POLYNOMIAL_H_

#include <gtest/gtest.h>
#include "../src/term.h"
#include "../src/polynomial.h"

TEST(PolynomialTest, CreatePolynomial) {
    Term *terms = new Term[4]{{-7, 0}, {6, 1}, {0, 2}, {1, 3}};
    Polynomial poly(terms, 3);
}

TEST(PolynomialTest, CopyOperator) {
    Term *terms = new Term[4]{{-7, 0}, {6, 1}, {0, 2}, {1, 3}};
    Polynomial p1(terms, 3);
    Polynomial p2 = p1;
    ASSERT_EQ(3, p2.getDegree());
    ASSERT_NEAR(-7, p2.getTermByExponent(0).getCoefficient(), 0.001);
    ASSERT_NEAR(6, p2.getTermByExponent(1).getCoefficient(), 0.001);
    ASSERT_NEAR(0, p2.getTermByExponent(2).getCoefficient(), 0.001);
    ASSERT_NEAR(1, p2.getTermByExponent(3).getCoefficient(), 0.001);
}

TEST(PolynomialTest, Destructor) {
    Term *terms = new Term[4]{{-7, 0}, {6, 1}, {0, 2}, {1, 3}};
    Polynomial p1(terms, 3);
}

TEST(PolynomialTest, PlusOperator) {
    Term *terms1 = new Term[4]{{-7, 0}, {6, 1}, {0, 2}, {1, 3}};
    Term *terms2 = new Term[3]{{-0.8, 0}, {0, 1}, {5, 2}};
    Polynomial p1(terms1, 3);
    Polynomial p2(terms2, 2);
    Polynomial p3 = p1 + p2;
    ASSERT_EQ(3, p3.getDegree());
    ASSERT_NEAR(-7.8, p3.getTermByExponent(0).getCoefficient(), 0.001);
    ASSERT_NEAR(6, p3.getTermByExponent(1).getCoefficient(), 0.001);
    ASSERT_NEAR(5, p3.getTermByExponent(2).getCoefficient(), 0.001);
    ASSERT_NEAR(1, p3.getTermByExponent(3).getCoefficient(), 0.001);
}

TEST(PolynomialTest, AssignmentOperator) {
    Term *terms = new Term[4]{{-7, 0}, {6, 1}, {0, 2}, {1, 3}};
    Polynomial p1(terms, 3);
    Polynomial p2(nullptr, 0);
    p2 = p1;
    ASSERT_EQ(3, p2.getDegree());
    ASSERT_NEAR(-7, p2.getTermByExponent(0).getCoefficient(), 0.001);
    ASSERT_NEAR(6, p2.getTermByExponent(1).getCoefficient(), 0.001);
    ASSERT_NEAR(0, p2.getTermByExponent(2).getCoefficient(), 0.001);
    ASSERT_NEAR(1, p2.getTermByExponent(3).getCoefficient(), 0.001);
}

TEST(PolynomialTest, Evaluate) {
    Term *terms = new Term[4]{{-7, 0}, {6, 1}, {0, 2}, {1, 3}};
    Polynomial p1(terms, 3);
    ASSERT_NEAR(13, p1.evaluate(2), 0.001);
}
#endif
