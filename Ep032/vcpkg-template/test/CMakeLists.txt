add_executable(unit_tests 
            lib1/lib1_test.cpp 
            lib2/lib2_test.cpp
            arithmetic/arithmetic_test.cpp
            core/core_test.cpp)
target_link_libraries(unit_tests PRIVATE core GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(unit_tests)