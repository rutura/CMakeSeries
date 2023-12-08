#[==[
    . Using doxygen to write documentation
    . There are two approaches: 
        1. Manually dealing with  the Dyxyfile and calling doxygen from it.
        2. Using the built-in doxygen module in CMake.
    . This project will explore option 1.
        . Introduce find_program
        . find_package will be introduced in the next project.

    . First, manually generate a doxyfile as shown below:
        1. doxygen -g
        2. Edit the doxyfile to your taste. (See the Doxyfile in the docs folder of this project.)
            . First do without awesome-css
            . Then do with awesome-css
        3. Run doxygen doxyfile from the root of the project.(location of root CMakeLists.txt)
        4. The documentation will be generated in the docs/build folder.

    . Secondly, we will rely on cmake to download the awesome-css files and running 
        doxygen in the root folder of the project. 
            . We will set up a target called documentation that will run doxygen in the root folder of the project.

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
