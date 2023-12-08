add_library(calculator calculator.cpp)
target_include_directories(calculator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(run_app run_app.cpp)
target_link_libraries(run_app PUBLIC calculator)