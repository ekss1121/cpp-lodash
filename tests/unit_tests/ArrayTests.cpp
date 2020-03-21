//
// Created by Zhihang Liu on 3/21/20.
//
#include "gtest/gtest.h"
#include "Array.h"
using namespace std;
using namespace CppLodash;
TEST(LodashArrayTest, canChunkIntegerVector)
{
    vector<int> test = {1,2,3,4};
    auto rst = Array<int>::chunk(test,2);
    EXPECT_EQ(rst.size(), 2u);
    EXPECT_EQ(rst[0].size(), 2u);
    EXPECT_EQ(rst[0][1], 2);
}

