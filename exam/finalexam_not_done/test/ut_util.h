#pragma once

#include <gtest/gtest.h>
#include <vector>
#include "../src/Binary.h"
#include "../src/uChar.h"
#include "../src/uShort.h"
#include "../src/uInt.h"
#include "../src/sInt.h"
#include "../src/util.h"

class UtilityTest : public ::testing::Test {
protected:
    void SetUp() override {
        b0 = new Binary(a0, 1);
        b1 = new Binary(a1, 8);
        b2 = new Binary(a2, 7);
        b3 = new Binary(a3, 9);
        b4 = new Binary(a4, 17);
        bins.push_back(b0);
        bins.push_back(b1);
        bins.push_back(b2);
        bins.push_back(b3);
        bins.push_back(b4);
    }

    void TearDown() override {
        delete b0;
        delete b1;
        delete b2;
        delete b3;
        delete b4;
    }

    int a0[1] = {1};
    int a1[8] = {1,0,1,0,0,0,0,0};
    int a2[7] = {0,1,0,0,0,0,0};
    int a3[9] = {0,1,0,0,0,0,0,0,1};
    int a4[17] = {0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1};
    Binary *b0, *b1, *b2, *b3, *b4;
    std::vector<Binary*> bins;
};

TEST_F(UtilityTest, FindAllDecSmaller) {
    std::vector<Binary*> result = findAll(bins.begin(), bins.end(), [](Binary*b) {return b->toDec() >= 258;});
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(258, result[0]->toDec());
    ASSERT_EQ(65794, result[1]->toDec());
}

TEST_F(UtilityTest, ConvertAlluChar) {
    std::vector<uChar> result = convertAll<uChar>(bins);
    ASSERT_EQ(3, result.size());
    ASSERT_EQ(1, result[0].toChar());
    ASSERT_EQ(5, result[1].toChar());
    ASSERT_EQ(2, result[2].toChar());
}
