#include "lib2.h"
#include "gtest/gtest.h"
#include <sstream>

namespace {

class Lib2Test : public ::testing::Test {
protected:
  lib2::MyClass2 obj;
  std::stringstream buffer;
  std::streambuf *sbuf;
  void SetUp() {
    sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
  }
  void TearDown() { std::cout.rdbuf(sbuf); }
};

TEST_F(Lib2Test, Function1Test) {
  obj.function1();
  std::string expected = "lib2::MyClass2::function1\n";
  EXPECT_EQ(buffer.str(), expected);
  buffer.str(std::string());
}

TEST_F(Lib2Test, Function2Test) {
  obj.function2();
  std::string expected = "lib2::MyClass2::function2\n";
  EXPECT_EQ(buffer.str(), expected);
  buffer.str(std::string());
}

TEST_F(Lib2Test, Function3Test) {
  obj.function3();
  std::string expected = "lib2::MyClass2::function3\n";
  EXPECT_EQ(buffer.str(), expected);
  buffer.str(std::string());
}

} // namespace