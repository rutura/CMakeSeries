#[==[
    . Introducing testing. Using the catch2 as a an example.
        . Doc : https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md
    . Start for the google test project and remove any code related to the google test framework
    . Go through the docs to the FetchContent part and make sure you point out the need for 
        . list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

    . Make sure to call the command to discover tests, as directed from the docs.

    . Build and run the tests.
#]==]

cmake_minimum_required(VERSION 3.20)

project(Dependencies)

enable_testing()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

add_executable(rooster main.cpp)
target_link_libraries(rooster PRIVATE calculator)

add_subdirectory(test)
