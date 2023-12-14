#include <catch2/catch_test_macros.hpp>

#include "lib.hpp"

TEST_CASE("Name is rooster", "[library]")
{
  auto const lib = library {};
  REQUIRE(lib.name == "rooster");
}
