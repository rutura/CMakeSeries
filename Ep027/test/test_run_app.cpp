#include <catch2/catch_test_macros.hpp>
#include <string>
#include <sstream>
#include <iostream>

#include "calculator.h"

extern int run_app(int argc, char** argv);

TEST_CASE("Test run_app function", "[run_app]") {
    // Redirect std::cout to a stringstream
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    run_app(1, nullptr);

    // Restore std::cout to its previous buffer
    std::cout.rdbuf(prevcoutbuf);

    // Check the output
    std::string expected_output = "add(10,4): 14\nsub(10,4): 6\nmul(10,4): 40\ndiv(10,4): 2\nmod(10,4): 2\n";
    REQUIRE(buffer.str() == expected_output);
}