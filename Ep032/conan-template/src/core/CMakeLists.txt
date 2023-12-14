# core/CMakeLists.txt

add_library(core core.cpp)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link the core library with the other libraries
target_link_libraries(core
    PUBLIC lib1 lib2 arithmetic fmt::fmt
)
