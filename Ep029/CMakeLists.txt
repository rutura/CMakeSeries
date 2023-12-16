#[==[
    . Using conan
        . Install conan: pip install conan
        . Set up the conanfile.py in the root directory of the project.
        . Install the dependencies: conan install . -s build_type=Debug -s compiler.cppstd=20 --output-folder=build --build missing
        . Configure: cmake -S . -B build
        . Build: cmake --build build

#]==]

cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_BINARY_DIR}/conan_toolchain.cmake")

project(Dependencies)

enable_testing()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Handle dependencies
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

#include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

find_package(Catch2 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(SFML COMPONENTS graphics CONFIG REQUIRED)

add_subdirectory(src)

add_executable(rooster main.cpp)
target_link_libraries(rooster PRIVATE run_app)

add_executable(gui gui.cpp)
target_link_libraries(gui PRIVATE sfml-graphics)

add_executable(use_fmt use_fmt.cpp)
target_link_libraries(use_fmt PRIVATE fmt::fmt)

add_subdirectory(test)

add_subdirectory(docs)