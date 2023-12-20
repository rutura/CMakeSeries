cmake_minimum_required(VERSION 3.15)
project(Rooster CXX)

find_package(sfml COMPONENTS graphics window system REQUIRED)

add_executable(Rooster src/main.cpp)
target_link_libraries(Rooster sfml-graphics)



install(TARGETS Rooster DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
