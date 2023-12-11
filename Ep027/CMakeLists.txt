#[==[
    . Using CPM for package management
      . It builds on top of FetchContent and provides a 
         different interface.

      . You specify the package name and the git url
         and it will download the package and build it
         for you. You can use tags, versions or both.

       . CPM failed to find the Catch custom module for some reason, and I had
          to manually hardwire the location in like so (See test/CMakeLists.txt)): 

          . list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/build/_deps/catch2-src/extras)

#]==]

cmake_minimum_required(VERSION 3.20)

project(Dependencies)

enable_testing()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Handle dependencies
include(CPM)

#Bring in the Catch2 testing library
CPMAddPackage("gh:catchorg/Catch2#v3.4.0")

#Bring in the fmt library
CPMAddPackage("gh:fmtlib/fmt#10.1.1")

#Bring in the SFML library
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
CPMAddPackage("gh:SFML/SFML#2.6.1")

add_subdirectory(src)

add_executable(rooster main.cpp)
target_link_libraries(rooster PRIVATE run_app)

add_executable(gui gui.cpp)
target_link_libraries(gui PRIVATE sfml-graphics)

add_executable(use_fmt use_fmt.cpp)
target_link_libraries(use_fmt PRIVATE fmt)

add_subdirectory(test)

add_subdirectory(docs)

message(STATUS "CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")
