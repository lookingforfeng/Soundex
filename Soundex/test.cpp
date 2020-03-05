#include "gtest/gtest.h"

TEST(TestCaseName, TestName1) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName2) {
    EXPECT_TRUE(1==1);
}

TEST(TestCaseName, TestName3) {
    EXPECT_FALSE(1!=1);
}

TEST(TestCaseName, TestName4) {
    EXPECT_TRUE(true);
    EXPECT_FALSE(false);
}