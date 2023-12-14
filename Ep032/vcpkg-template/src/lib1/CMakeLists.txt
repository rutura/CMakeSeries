# lib1/CMakeLists.txt

add_library(lib1 lib1.cpp)
target_include_directories(lib1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
