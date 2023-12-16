#[=[
     Exploring CMake's Custom Targets, custom modules and code formatting with clang-format
        . Go from the clang-format official reference: 
                . https://clangpowertools.com/blog/getting-started-with-clang-format-style-options.html
        . Start with a simple C++ project containing a main.cpp and a person.cpp file
        . Manually format the code with clang-format
        . Add a function to format the code with clang-format
        . Move the function to a custom module
        . You can force the formatting by making the rooster target depend on the format-code target
        . Reference to learn more about add_custom_command: 
                . https://gist.github.com/baiwfg2/39881ba703e9c74e95366ed422641609
#]=]


cmake_minimum_required(VERSION 3.21) # At least version 3.21 is required for C++23
project(CustomTargets) # Replace with your project name

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(rooster main.cpp person.cpp) # Replace with your source files
target_include_directories(rooster PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

include(ClangFormat)
add_clang_format_target(format-code ${PROJECT_SOURCE_DIR})
add_dependencies(rooster format-code)