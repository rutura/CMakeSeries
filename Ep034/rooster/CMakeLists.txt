cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    Rooster
    VERSION 0.1.0
    DESCRIPTION "This is a starter C++ project using CMake"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    Rooster_lib OBJECT
    source/lib.cpp
)

target_include_directories(
    Rooster_lib ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(Rooster_lib PUBLIC cxx_std_20)

find_package(fmt REQUIRED)
target_link_libraries(Rooster_lib PRIVATE fmt::fmt)

# ---- Declare executable ----

add_executable(Rooster_exe source/main.cpp)
add_executable(Rooster::exe ALIAS Rooster_exe)

set_property(TARGET Rooster_exe PROPERTY OUTPUT_NAME Rooster)

target_compile_features(Rooster_exe PRIVATE cxx_std_20)

target_link_libraries(Rooster_exe PRIVATE Rooster_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT Rooster_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of Rooster"
  )
endif()

include(cmake/dev-mode.cmake)
