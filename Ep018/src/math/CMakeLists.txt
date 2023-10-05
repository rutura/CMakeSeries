# The math library
set(OUR_PROJECT_VERSION "Two")
add_library(libmath STATIC supermath.cpp)
target_include_directories(libmath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)