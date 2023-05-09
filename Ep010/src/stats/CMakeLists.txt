# The stats library
add_library(libstats STATIC stats.cpp)
target_include_directories(libstats PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(libstats PUBLIC libmath)