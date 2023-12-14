// arithmetic.cpp

#include "arithmetic.h"
#include <iostream>

namespace Arithmetic {

int Math::add(int a, int b) {
  auto result = a + b;
  return result;
}

int Math::sub(int a, int b) { return a - b; }

int Math::mult(int a, int b) { return a * b; }

} // namespace Arithmetic
