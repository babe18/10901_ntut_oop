#ifndef _UT_TERM_H_
#define _UT_TERM_H_

#include <gtest/gtest.h>
#include "../src/term.h"

class TermTest : public ::testing::Test {
protected:
    void SetUp() override {
        term1 = new Term(-4.5, 7);
        term2 = new Term(-4.5, 7);
        term3 = new Term(3.0, 4);
        term4 = new Term(4.0, 4);
    }

    void TearDown() override {
        delete term1;
        delete term2;
        delete term3;
        delete term4;
    }
    Term *term1, *term2, *term3, *term4;
};

TEST_F(TermTest, CreateTermWithoutArgument) {
    Term term;
    ASSERT_NEAR(0, term.getCoefficient(), 0.001);
    ASSERT_EQ(0, term.getExponent());
}

TEST_F(TermTest, CreateTermWithArgument) {
    Term term(4.5, 5);
    ASSERT_NEAR(4.5, term.getCoefficient(), 0.001);
    ASSERT_EQ(4.5, term.getCoefficient());
    ASSERT_EQ(5, term.getExponent());
}

TEST_F(TermTest, AssignmentOperator) {
    Term term;
    term = *term1;
    ASSERT_NEAR(-4.5, term.getCoefficient(), 0.001);
    ASSERT_EQ(7, term.getExponent());
}

TEST_F(TermTest, PlusOperator) {
    Term term = *term3 + *term4;
    ASSERT_NEAR(7, term.getCoefficient(), 0.001);
}

TEST_F(TermTest, ExceptionPlusOperation) {
    ASSERT_ANY_THROW(*term2 + *term3);
}

TEST_F(TermTest, Evaluate) {
    ASSERT_NEAR(48.000, term3->evaluate(2), 0.001);
}

#endif
