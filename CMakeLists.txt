cmake_minimum_required(VERSION 3.5)
project(effective-cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package(Boost)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif ()

set(SOURCE_FILES
        main.cpp main.cpp
        ch1_type_ded.cpp Chap.h
        ch2_auto.cpp ch3_modern_cpp.cpp)

add_executable(effective-cpp ${SOURCE_FILES})