#[==[
    . Using doxygen to write documentation
        . Reference: https://www.doxygen.nl/manual/starting.html
    . There are two approaches: 
        1. Manually dealing with  the Dyxyfile and calling doxygen from it.
        2. Using the built-in doxygen module in CMake.
    . This project will explore option 1.

#]==]

cmake_minimum_required(VERSION 3.20)

project(Dependencies)

enable_testing()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

add_executable(rooster main.cpp)
target_link_libraries(rooster PRIVATE run_app)

add_subdirectory(test)

add_subdirectory(docs)
