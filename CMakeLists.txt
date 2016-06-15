cmake_minimum_required(VERSION 3.5)
project(effective-cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp main.cpp
        i01_type_ded.cpp)

add_executable(effective-cpp ${SOURCE_FILES})