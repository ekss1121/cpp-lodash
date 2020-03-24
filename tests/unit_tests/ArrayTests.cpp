//
// Created by Zhihang Liu on 3/21/20.
//
#include "gtest/gtest.h"
#include "Array.h"
#include <typeinfo>
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

TEST(LodashArrayTest, canCompactIntegerVector)
{
    vector<int> test = {1,0,2,3,4};
    auto rst = Array<int>::compact(test);
    EXPECT_EQ(rst.size(), 4u);
    EXPECT_EQ(rst[1], 2);
}

TEST(LodashArrayTest, canConcatIntegers)
{
    vector<int> v1{1,2};
    vector<int> v2{3,4};
    vector<int> v3{5,6};
    auto rst = Array<int>::concat(v1, v2, v3);
    EXPECT_EQ(rst.size(), 6u);
}

TEST(LodashArrayTest, canDifferenceIntegers)
{
    vector<int> v1{1,2};
    vector<int> filter{1,3};
    auto rst = Array<int>::difference(v1, filter);
    EXPECT_EQ(rst.size(), 1u);
    EXPECT_EQ(rst[0], 2);

}