# The math library
add_library(libmath STATIC src/math/supermath.cpp)
target_include_directories(libmath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/math/include)