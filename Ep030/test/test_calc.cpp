#include <catch2/catch_test_macros.hpp>
#include "calculator.h"

TEST_CASE("CalculatorTest - Add", "[Calculator]") {
    Calculator calc;
    REQUIRE(calc.add(2, 3) == 5);
    REQUIRE(calc.add(-2, 3) == 1);
    REQUIRE(calc.add(0, 0) == 0);
}

TEST_CASE("CalculatorTest - Sub", "[Calculator]") {
    Calculator calc;
    REQUIRE(calc.sub(5, 3) == 2);
    REQUIRE(calc.sub(3, 5) == -2);
    REQUIRE(calc.sub(0, 0) == 0);
}

TEST_CASE("CalculatorTest - Mul", "[Calculator]") {
    Calculator calc;
    REQUIRE(calc.mul(2, 3) == 6);
    REQUIRE(calc.mul(-2, 3) == -6);
    REQUIRE(calc.mul(0, 5) == 0);
}

TEST_CASE("CalculatorTest - Div", "[Calculator]") {
    Calculator calc;
    REQUIRE(calc.div(6, 3) == 2);
    REQUIRE(calc.div(5, 2) == 2);
}

TEST_CASE("CalculatorTest - Mod", "[Calculator]") {
    Calculator calc;
    REQUIRE(calc.mod(6, 4) == 2);
    REQUIRE(calc.mod(5, 2) == 1);
}
