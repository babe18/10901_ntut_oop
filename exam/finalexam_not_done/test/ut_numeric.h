#pragma once

#include <gtest/gtest.h>
#include <sstream>
#include "../src/Binary.h"
#include "../src/uChar.h"
#include "../src/uShort.h"
#include "../src/uInt.h"
#include "../src/sInt.h"

class NumericTest : public ::testing::Test {
protected:
    void SetUp() override {
        b0 = new Binary(a0, 2);
        b1 = new Binary(a1, 8);
        b2 = new Binary(a2, 7);
        b3 = new Binary(a3, 9);
        b4 = new Binary(a4, 17);
    }

    void TearDown() override {
        delete b0;
        delete b1;
        delete b2;
        delete b3;
        delete b4;
    }

    int a0[2] = {1, 0}; // 1
    int a1[8] = {1,0,0,0,0,0,0,0}; // 1
    int a2[7] = {0,1,0,0,0,0,0};
    int a3[9] = {0,1,0,0,0,0,0,0,1};
    int a4[17] = {0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1};
    Binary *b0, *b1, *b2, *b3, *b4;
};


// TEST_F(NumericTest, UCharDefaultConstructor) {
//     uChar *uc = new uChar(*b1);
//     ASSERT_EQ(1, uc->toChar());
//     delete uc;
// }

// TEST_F(NumericTest, UCharCanConvertTrue) {
//     ASSERT_EQ(true, uChar::canConvert(*b1));
// }

TEST_F(NumericTest, UShortDefaultConstructor) {
    uShort *us = new uShort(*b1);
    ASSERT_EQ(1, us->toDec());
}

// TEST_F(NumericTest, UShortCanConvertTrue) {
//     ASSERT_EQ(true, uShort::canConvert(*b1));
// }

TEST_F(NumericTest, UIntDefaultConstructor) {
    uInt *ui = new uInt(*b1);
    ASSERT_EQ(1, ui->toDec());
}

// TEST_F(NumericTest, UIntCanConvertTrue) {
//     ASSERT_EQ(true, uInt::canConvert(*b1));
// }

// TEST_F(NumericTest, SIntDefaultConstructor) {
//     sInt si('-', *b1);
//     ASSERT_EQ(-1, si.toDec());
// }

// TEST_F(NumericTest, SIntFromString) {
//     std::stringstream ss;
//     ss << "- 4 {1,1,0,1}";
//     sInt *si = new sInt('-', *b1);
//     si->fromString(ss);
//     ASSERT_EQ(-13, si->toDec());
// }
