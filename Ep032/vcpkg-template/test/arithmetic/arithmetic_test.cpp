#include "arithmetic.h"
#include "gtest/gtest.h"

namespace {

class ArithmeticTest : public ::testing::Test {
protected:
  Arithmetic::Math math;
};

TEST_F(ArithmeticTest, AddTest) {
  EXPECT_EQ(math.add(10, 5), 15);
  EXPECT_EQ(math.add(-10, 5), -5);
  EXPECT_EQ(math.add(0, 0), 0);
}

TEST_F(ArithmeticTest, SubTest) {
  EXPECT_EQ(math.sub(10, 5), 5);
  EXPECT_EQ(math.sub(-10, 5), -15);
  EXPECT_EQ(math.sub(0, 0), 0);
}

TEST_F(ArithmeticTest, MultTest) {
  EXPECT_EQ(math.mult(10, 5), 50);
  EXPECT_EQ(math.mult(-10, 5), -50);
  EXPECT_EQ(math.mult(0, 0), 0);
}

} // namespace