#[==[
    . How do you test the code in the main.cpp? 
    . Extract the code into the run_app library
    . Link rooster to the run_app library
    . Also link the unit_test target to the run_app library
#]==]

cmake_minimum_required(VERSION 3.20)

project(Dependencies)

enable_testing()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

add_executable(rooster main.cpp)
target_link_libraries(rooster PRIVATE calculator run_app)

add_subdirectory(test)
