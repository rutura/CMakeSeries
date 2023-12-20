#[==[
    . Presets. Why? 
        . They are a way to configure your project in a declarative way.
        . They make it easy to configure your project for different platforms.
        . Sharing your project configuration is easy.
        . IDEs and editors use them to configure your project. This makes it easy to switch between them.
    . Using CMakePresents with a vcpkg powered project.
    . Remember to have this content in your settings.json file for the status bar to show up.

            {
                "cmake.useCMakePresets": "always",
                "cmake.options.statusBarVisibility": "visible"
            }
    . Show how to use them from the terminal
    . Then use them from VSCode
    . Show how to debug
    . Show test integration. [Sometimes need to reload VSCode]


#]==]

cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

project(Dependencies)

enable_testing()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Handle dependencies
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# include("$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

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