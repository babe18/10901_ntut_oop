#pragma once

#include <gtest/gtest.h>
#include "../src/Binary.h"

class BinaryTest : public ::testing::Test {
protected:
    void SetUp() override {
        b1 = new Binary(a1, 8);
        b2 = new Binary(a2, 7);
    }

    void TearDown() override {
        delete b1;
        delete b2;
    }

    int a1[8] = {1,0,0,0,0,0,0,0};
    int a2[7] = {0,1,0,0,0,0,0};
    Binary *b1, *b2;
};

TEST_F(BinaryTest, GetIndex) {
    ASSERT_EQ(1, b1->at(0));
}

TEST_F(BinaryTest, CreateBinary) {
    ASSERT_EQ(1, b1->toDec());
    ASSERT_EQ(2, b2->toDec());
}

TEST_F(BinaryTest, FillWithZero) {
    Binary b3 = b2->fillWithZero(8);
    ASSERT_EQ(0, b3.at(7));
}

TEST_F(BinaryTest, InsertionOperator) {
    std::stringstream ss;
    ss << *b1;
    ASSERT_EQ("{0,0,0,0,0,0,0,1}", ss.str());
}

// TEST_F(BinaryTest, ExtractionOperator) {
//     std::stringstream ss;
//     Binary b;
//     ss << "{1}";
//     ss >> b;
//     ASSERT_EQ(1, b.toDec());
//     ASSERT_EQ(1, b.at(0));
//     ASSERT_ANY_THROW(b.at(1));
// }
