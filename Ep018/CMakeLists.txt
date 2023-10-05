#[=[

	Show cmake variables in the context of a project
		. Root level
		. Included CMakeLists.txt files
		. Show that 
			. add_subdriectory adds a new variable scope
			. include still works in the global scope. Contrast this with the project in Ep009 where we used include

	Show cache variables 

	Show environment variables (Windows)

	Show how to use functions
        . The create_and_link_executable function will wrap around the commands
            . add_executable
            . target_link_libraries

	Show gui tools 
		. cmake-gui (Windows)
		. ccmake (Linux-Mac)
		. Higlight the three stages of cmake
			. Configuration
			. Generation
			. Build

#]=]

cmake_minimum_required(VERSION 3.20)

project(Rooster)

# The include command sets up a new variable scope. The OUR_PROJECT_VERSION variable is being set in the 
# three CMakeLists.txt files. We will see output saying that the project version is "One" because the variables
# set in included files live in their own scope.
set(OUR_PROJECT_VERSION "One")

#Set up a cache variable named THE_SKY_IS_BLUE
set(THE_SKY_IS_BLUE "Yes" CACHE STRING "Is the sky blue?")

# The math library
add_subdirectory(src/math)

# The stats library
add_subdirectory(src/stats)

#Set the source files to use
set(SOURCE_FILES
    src/main.cpp
    src/information.cpp 
    src/information.h
)

function(create_and_link_executable EXEC_NAME LIB_NAME SOURCES)
    add_executable(${EXEC_NAME} ${${SOURCES}})
    target_link_libraries(${EXEC_NAME} PUBLIC ${LIB_NAME} )
endfunction()

#The executable target
# add_executable(rooster ${SOURCE_FILES})
# target_link_libraries(rooster PUBLIC libstats)

create_and_link_executable(rooster libstats SOURCE_FILES)

message("Our project version is ${OUR_PROJECT_VERSION}")
message("Custom message: The compiler we're using is ${CMAKE_CXX_COMPILER}")
message("The processor architecture is $ENV{PROCESSOR_ARCHITECTURE}")
message(${THE_SKY_IS_BLUE})