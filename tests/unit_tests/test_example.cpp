#include "gtest/gtest.h"
#include "Array.h"
#include <vector>
using namespace std;
TEST(Example, Equals) {
    vector<int> v{1,2,3,4};
    CppLodash::Array<int>::chunk(v, 2);
  EXPECT_EQ(1, 1);
}