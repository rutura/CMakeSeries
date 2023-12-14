#include "core.h"
#include "gtest/gtest.h"
#include <sstream>

namespace {

class CoreTest : public ::testing::Test {
protected:
  core::CoreClass obj;
  std::stringstream buffer;
  std::streambuf *sbuf;
  void SetUp() {
    sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
  }
  void TearDown() { std::cout.rdbuf(sbuf); }
};

TEST_F(CoreTest, UseLib1Test) {
  obj.useLib1();
  std::string expected = "lib1::MyClass1::function1\nlib1::MyClass1::"
                         "function2\nlib1::MyClass1::function3\n";
  EXPECT_EQ(buffer.str(), expected);
  buffer.str(std::string());
}

TEST_F(CoreTest, UseLib2Test) {
  obj.useLib2();
  std::string expected = "lib2::MyClass2::function1\nlib2::MyClass2::"
                         "function2\nlib2::MyClass2::function3\n";
  EXPECT_EQ(buffer.str(), expected);
  buffer.str(std::string());
}

TEST_F(CoreTest, UseArithmeticTest) {
  obj.useArithmetic();
  std::string expected = "Adding 10 and 5 gives 15.\nSubtracting 10 and 5 "
                         "gives 5.\nMultiplying 10 and 5 gives 50.\n";
  EXPECT_EQ(buffer.str(), expected);
  buffer.str(std::string());
}

TEST_F(CoreTest, AppTest) {
  int argc = 1;
  char *argv[] = {(char *)"program name", NULL};
  app(argc, argv);
  std::string expected =
      "lib1::MyClass1::function1\nlib1::MyClass1::function2\nlib1::MyClass1::"
      "function3\nlib2::MyClass2::function1\nlib2::MyClass2::function2\nlib2::"
      "MyClass2::function3\nAdding 10 and 5 gives 15.\nSubtracting 10 and 5 "
      "gives 5.\nMultiplying 10 and 5 gives 50.\n";
  EXPECT_EQ(buffer.str(), expected);
  buffer.str(std::string());
}
} // namespace
