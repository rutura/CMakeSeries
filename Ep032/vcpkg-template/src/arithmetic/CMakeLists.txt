# lib3/CMakeLists.txt

add_library(arithmetic arithmetic.cpp)
target_include_directories(arithmetic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
