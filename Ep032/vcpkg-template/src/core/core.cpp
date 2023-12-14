// core.cpp

#include "core.h"
#include <fmt/format.h>
#include <iostream>

namespace core {

void CoreClass::useLib1() {
  lib1::MyClass1 obj1;
  obj1.function1();
  obj1.function2();
  obj1.function3();
}

void CoreClass::useLib2() {
  lib2::MyClass2 obj2;
  obj2.function1();
  obj2.function2();
  obj2.function3();
}

void CoreClass::useArithmetic() {
  Arithmetic::Math obj3;
  std::cout << fmt::format("Adding 10 and 5 gives {}.", obj3.add(10, 5))
            << std::endl;
  std::cout << fmt::format("Subtracting 10 and 5 gives {}.", obj3.sub(10, 5))
            << std::endl;
  std::cout << fmt::format("Multiplying 10 and 5 gives {}.", obj3.mult(10, 5))
            << std::endl;
}

} // namespace core

// The logic of the application
void app(int argc, char **argv) {
  core::CoreClass obj;
  obj.useLib1();
  obj.useLib2();
  obj.useArithmetic();
}
