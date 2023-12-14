#[==[
    . This project just showcases the use of the cmake-init tool.
      . We generate a c++ project using vcpkg as package manager.
      . It also has doxygen and clang format integrated.

#]==]

cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    rooster
    VERSION 0.1.0
    DESCRIPTION "A starter C++ project"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    rooster_lib OBJECT
    source/lib.cpp
)

target_include_directories(
    rooster_lib ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(rooster_lib PUBLIC cxx_std_20)

find_package(fmt REQUIRED)
target_link_libraries(rooster_lib PRIVATE fmt::fmt)

# ---- Declare executable ----

add_executable(rooster_exe source/main.cpp)
add_executable(rooster::exe ALIAS rooster_exe)

set_property(TARGET rooster_exe PROPERTY OUTPUT_NAME rooster)

target_compile_features(rooster_exe PRIVATE cxx_std_20)

target_link_libraries(rooster_exe PRIVATE rooster_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT rooster_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of rooster"
  )
endif()

include(cmake/dev-mode.cmake)
