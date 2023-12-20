#[==[
    . Using conan
        . Install conan: pip install conan
        . Set up the conanfile.py in the root directory of the project.
        . Install the dependencies: conan install . -s build_type=Debug -s compiler.cppstd=20 --output-folder=build --build missing
            . This will generate the preset files for you

        . Configure and build: 
            . In VSCode: 
                . Set up your presets and clic on the buttons.
                . After you configure and build, you may need to restart VSCode
                    for the tests to integrate correctly.
            . On the terminal
                . Configure: cmake -S . -B build
                . Build: cmake --build build

#]==]


#The root CMakeLists.txt file.
cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_BINARY_DIR}/conan_toolchain.cmake")

project(Rooster  VERSION 1.0.0 LANGUAGES CXX)
enable_testing()
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

#Require C++20
set(CXX_STANDARD_REQUIRED ON) #Make C++20 a hard requirement
set(CMAKE_CXX_STANDARD 20) # Default C++ standard for targets

#Bring in the dependencies

find_package(fmt CONFIG REQUIRED)
find_package(sfml CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


add_subdirectory(src/lib1)

add_subdirectory(src/lib2)

add_subdirectory(src/arithmetic)

add_subdirectory(src/core)

# Create an executable that uses the core library
add_executable(rooster src/main/main.cpp)
target_link_libraries(rooster PRIVATE sfml-graphics)

# Link the executable with the core library
target_link_libraries(rooster
    PRIVATE core
)

include(ClangFormat)
add_clang_format_target(format-code ${PROJECT_SOURCE_DIR})

add_subdirectory(test)

add_subdirectory(docs)
