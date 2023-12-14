#include "lib1.h"
#include "gtest/gtest.h"
#include <sstream>

namespace {

class Lib1Test : public ::testing::Test {
protected:
  lib1::MyClass1 obj;
  std::stringstream buffer;
  std::streambuf *sbuf;
  void SetUp() {
    sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
  }
  void TearDown() { std::cout.rdbuf(sbuf); }
};

TEST_F(Lib1Test, Function1Test) {
  obj.function1();
  std::string expected = "lib1::MyClass1::function1\n";
  EXPECT_EQ(buffer.str(), expected);
  buffer.str(std::string());
}

TEST_F(Lib1Test, Function2Test) {
  obj.function2();
  std::string expected = "lib1::MyClass1::function2\n";
  EXPECT_EQ(buffer.str(), expected);
  buffer.str(std::string());
}

TEST_F(Lib1Test, Function3Test) {
  obj.function3();
  std::string expected = "lib1::MyClass1::function3\n";
  EXPECT_EQ(buffer.str(), expected);
  buffer.str(std::string());
}

} // namespace