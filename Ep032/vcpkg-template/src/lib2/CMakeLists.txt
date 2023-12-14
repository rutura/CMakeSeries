# lib2/CMakeLists.txt

add_library(lib2 lib2.cpp)

target_include_directories(lib2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
