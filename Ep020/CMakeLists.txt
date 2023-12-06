#[==[
    . Using the google test reference 
        . https://google.github.io/googletest/quickstart-cmake.html
    . Update to use the latest version of google test on github. Pick the tag
    . Start with the calculator files in the root and build the project
    . Then move them into src and add the subdirectory
    . Move on to add the test folder and adapt the FetchContent code
    . Add the test folder and add the subdirectory. Make sure to put the enable_testing thing
        right after the project command.
    . Make sure to explain the theory of FetchContent in the slides. Especially how it 
        exposes the targets to your applications.

#]==]

cmake_minimum_required(VERSION 3.20)

project(Dependencies)

enable_testing()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

add_executable(rooster main.cpp)
target_link_libraries(rooster PRIVATE calculator)

add_subdirectory(test)
