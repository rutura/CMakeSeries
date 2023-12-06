include(AddCatch2)

add_executable(
  unit_tests
  test_calc.cpp
  test_run_app.cpp
)
target_link_libraries(
  unit_tests PRIVATE run_app Catch2::Catch2WithMain
)

include(CTest)
include(Catch)
catch_discover_tests(unit_tests)