cmake_minimum_required(VERSION 3.5)
project(effective-cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package(Boost)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif ()

set(SOURCE_FILES
        main.cpp main.cpp
        i01_type_ded.cpp Item.h)

add_executable(effective-cpp ${SOURCE_FILES})