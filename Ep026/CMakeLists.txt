#[==[
    . Using doxygen to write documentation
    . There are two approaches: 
        1. Manually dealing with  the Dyxyfile and calling doxygen from it.
        2. Using the built-in doxygen module in CMake.
    . This project will explore option 2.
        . We will take the chance to introduce find_package and find module files.

    . First, remove the add_custom_target and add_custom_command from the CMakeLists.txt file.
    . Add the doxygen_add_docs command and make sure we have the proper settings.
    . The doxygen_add_docs command will create a target called documentation, and will handle
        all the Doxyfile machinery so you don't have to worry about it.
    . These are two common ways to do things, you can choose whichever you prefer.

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
