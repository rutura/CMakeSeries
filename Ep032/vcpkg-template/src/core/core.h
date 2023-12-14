// core.hpp

#pragma once

// Include necessary headers from other libraries
#include "arithmetic.h"
#include "lib1.h"
#include "lib2.h"

namespace core {

class CoreClass {
public:
  /**
      @brief Function that tests out lib1
  */
  void useLib1();
  /**
      @brief Function that tests out lib2
  */
  void useLib2();
  /**
      @brief Function that tests out arithmetic
  */
  void useArithmetic();
};

} // namespace core

/**
    @brief Function that contains the main logic of the application
*/
void app(int argc, char **argv);
