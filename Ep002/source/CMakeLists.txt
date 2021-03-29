cmake_minimum_required(VERSION 3.5)
project(HelloApp
        VERSION 0.0.1
        DESCRIPTION "The leading Hello World App"
        LANGUAGES CXX)  

#Target
add_executable(HelloAppBinary main.cpp)
target_compile_features(HelloAppBinary PRIVATE cxx_std_20)