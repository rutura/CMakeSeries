#[==[
    . Using vcpkg
    . Install vcpkg
    . Point to the location of vcpkg through the include: 
        . include("$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
        . You can also set the environment variable before the call the the project command,
            as stated in the docs: https://learn.microsoft.com/en-us/vcpkg/consume/manifest-mode?tabs=cmake%2Cbuild-MSBuild

    . Add the vcpkg.json file to the root of the project

    . For automatic dependency pulling, sett the toolchain file variable.

#]==]

cmake_minimum_required(VERSION 3.20)

# set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

project(Dependencies)

enable_testing()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Handle dependencies
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include("$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

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

message(STATUS "CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")
